//
//  WebSocketTestScene.cpp
//  Reversi
//
//  Created by Kosuke Takami on 2015/05/09.
//
//

#include "WebSocketTestScene.h"
#include "json/rapidjson.h"
#include "json/document.h"
#include "SocketIOWrapper.h"

USING_NS_CC;
// UI関係
const static int PLAYER_TEXT_X = 900;
const static int OTHER_TEXT_X = 50;
const static int TEXT_H = 60;

Scene* WebSocketTestScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = WebSocketTestScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool WebSocketTestScene::init()
{
    index = 0;
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    //Size visibleSize = Director::getInstance()->getVisibleSize();
    Size visibleSize = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // texture load
    
    editBox = TextField::create("please input text", "Meiryo", 40);
    editBox->setContentSize(Size(visibleSize.width, 50));
    editBox->setPosition(Point(visibleSize.width / 2, 30));
    editBox->addEventListener(CC_CALLBACK_2(WebSocketTestScene::textFieldEvent, this));
    this->addChild(editBox);
    
    //ここでsocket.io connection開始。clientを持っておく。
    //_client = SocketIO::connect("http://localhost:3000", *this);
    //_client->on("hello", CC_CALLBACK_2(WebSocketTestScene::onReceiveEvent, this));
    
    //SocketIOWrapper *sample = new SocketIOWrapper();
    _client = SocketIOWrapper::create();
    //sample->func("http://google.com");
    _client->connect();
    
    return true;
}

void WebSocketTestScene::onConnect(SIOClient* client)
{
    log("connect success");
}

void WebSocketTestScene::onMessage(SIOClient* client, const std::string& data)
{
    log("send receive");
}

void WebSocketTestScene::onClose(SIOClient* client)
{
    log("disconnect success");
}

void WebSocketTestScene::onError(cocos2d::network::SIOClient *client, const std::string &data)
{
    log("failed");
}

void WebSocketTestScene::onReceiveEvent(cocos2d::network::SIOClient *client, const std::string &data)
{
    rapidjson::Document doc;
    doc.Parse<rapidjson::kParseDefaultFlags>(data.c_str());
    rapidjson::Value &val = doc["args"];
    std::string value = val[rapidjson::SizeType(0)]["value"].GetString();
    
    addTalkOther(value);
}

void WebSocketTestScene::textFieldEvent(Ref *pSender, TextField::EventType type)
{
    TextField* text;
    std::string sendText;
    std::string eventName;
    std::string emitKey;
    std::string message;
    switch(type)
    {
        case TextField::EventType::DETACH_WITH_IME:
            text = (TextField*) pSender;
            
            //_client->emit("hello", sendText);
            eventName = "hello";
            emitKey = "value";
            message = text->getString();
            _client->emit(eventName, emitKey, message);
            addTalkPlayer(text->getStringValue());
            break;
        default:
            break;
    }
}

void WebSocketTestScene::addTalkPlayer(const std::string &str)
{
    Size size = Director::getInstance()->getVisibleSize();
    
    DrawNode* draw = DrawNode::create();
    
    int originalX = PLAYER_TEXT_X;
    int originalY = size.height - (TEXT_H * (index + 1));
    
    int x = originalX - 290;
    int y = originalY - 60;
    int w = 300;
    int h = 60;
    
    Vec2 points[] = {
        Vec2(x , y),
        Vec2(x + w , y),
        Vec2(x + w , y + h),
        Vec2(x , y + h),
    };
    
    this->addChild(draw);
    draw->drawPolygon(points, 4, Color4F(0 , 0.5, 0, 1), 1, Color4F(0,0,1,1));
    
    auto text = Text::create(str, "Meiryo", 40);
    text->setTextHorizontalAlignment(TextHAlignment::RIGHT);
    text->setAnchorPoint(Point(1.0 , 1.0));
    text->setPosition(Point(originalX , originalY));
    
    this->addChild(text);
    index++;
}

void WebSocketTestScene::addTalkOther(const std::string &str)
{
    Size size = Director::getInstance()->getVisibleSize();
    
    DrawNode* draw = DrawNode::create();
    
    int originalX = OTHER_TEXT_X;
    int originalY = size.height - (TEXT_H * (index + 1));
    
    int x = originalX - 10;
    int y = originalY - 60;
    int w = 300;
    int h = 60;
    
    Vec2 points[] = {
        Vec2(x , y),
        Vec2(x + w , y),
        Vec2(x + w , y + h),
        Vec2(x , y + h),
    };
    
    this->addChild(draw);
    draw->drawPolygon(points, 4, Color4F(0.5, 0, 0, 1), 1, Color4F(1,0,0,1));
    
    auto text = Text::create(str, "Meiryo", 40);
    text->setTextHorizontalAlignment(TextHAlignment::LEFT);
    text->setAnchorPoint(Point(0.0 , 1.0));
    text->setPosition(Point(originalX , originalY));
    text->setColor(Color3B(255, 255, 0));
    this->addChild(text);
    index++;
}
