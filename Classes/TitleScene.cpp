//
//  TitleScene.cpp
//  Reversi
//
//  Created by Kosuke Takami on 2015/05/03.
//
//

#include "TitleScene.h"
#include "GameMainScene.h"

USING_NS_CC;

Scene* TitleScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = TitleScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool TitleScene::init()
{
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
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("textures.plist");
    
    /////////////////////////////
    // add background sprite
    Sprite *backgroundSprite = Sprite::createWithSpriteFrameName("background.png");
    
    // position the backgroundSprite on the center of the screen
    backgroundSprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the backgroundSprite as a child to this layer
    this->addChild(backgroundSprite, 0);
    
    MenuItemFont* toPvpFont = MenuItemFont::create("友達と", CC_CALLBACK_1(TitleScene::toPvp, this));
    Size s = Director::getInstance()->getVisibleSize();
    
    Menu* pMenu = Menu::create(toPvpFont, NULL);
    
    pMenu->setPosition(Vec2(s.width * .5, s.height * .5));
    
    this->addChild(pMenu);
    
    return true;
}

void TitleScene::toPvp(Ref* pSender)
{
    log("toPvp");
    
    auto *scene = GameMain::createScene();
    
    TransitionCrossFade* crossFade = TransitionCrossFade::create(0.5f, scene);
    
    Director::getInstance()->replaceScene(crossFade);
}