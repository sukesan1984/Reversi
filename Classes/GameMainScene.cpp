#include "GameMainScene.h"
#include "TitleScene.h"
USING_NS_CC;

Scene* GameMain::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameMain::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameMain::init()
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

    /////////////////////////////
    // create buttons
    /////////////////////////////
    Sprite *homeButton         = Sprite::createWithSpriteFrameName("home_button.png");
    Sprite *homeButtonSelected = Sprite::createWithSpriteFrameName("home_button.png");
    homeButtonSelected->setColor(Color3B::GRAY);
    
    auto homeItem = MenuItemSprite::create(homeButton, homeButtonSelected, CC_CALLBACK_1(GameMain::onClickHomeButton, this));
    homeItem->setPosition(Vec2(origin.x + visibleSize.width - homeItem->getContentSize().width / 2 - 20,
                               origin.y + visibleSize.height - homeItem->getContentSize().height / 2 - 20));
    
    Sprite *settingButton         = Sprite::createWithSpriteFrameName("setting_button.png");
    Sprite *settingButtonSelected = Sprite::createWithSpriteFrameName("setting_button.png");
    settingButtonSelected->setColor(Color3B::GRAY);
    
    auto settingItem = MenuItemSprite::create(settingButton, settingButtonSelected, CC_CALLBACK_1(GameMain::onClickSettingButton, this));
    
    settingItem->setPosition(Vec2(origin.x + settingItem->getContentSize().width / 2 + 20,
                               origin.y + visibleSize.height - settingItem->getContentSize().height / 2 - 20));
    
    auto menu = Menu::create(homeItem, settingItem, NULL);
    
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    // create board
    const int offsetY = 40;
    this->boardBuilder = new BoardBuilder(this, _eventDispatcher);
    this->boardModel   = new BoardModel();
    
    this->boardController = this->boardBuilder->create(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y - offsetY), this->boardModel);
    
    Player* playerBlack =  new Player(Color::Black);
    this->boardController->setOnClickHandler(TouchDelegate<Player>::createDelegator(playerBlack, &Player::onCellClick));
    
    //SelectWithWeighting* playerBlack = new SelectWithWeighting(Color::Black, this->boardModel);
    
    //Player* playerWhite =  new Player(Color::White);
    //this->boardController->setOnClickHandler(TouchDelegate<Player>::createDelegator(playerWhite, &Player::onCellClick));
    
    //SelectRandomPlayer* playerWhite =  new SelectRandomPlayer(Color::White, this->boardModel);
    //SelectMakeOponentFewPlacesPlayer* playerWhite =  new SelectMakeOponentFewPlacesPlayer(Color::White, this->boardModel);
    SelectWithWeighting* playerWhite =  new SelectWithWeighting(Color::White, this->boardModel);
    //this->boardController->setOnClickHandler(TouchDelegate<Player>::createDelegator(playerWhite, &Player::onCellClick));
    
    //create score background
    const int scoreBoardMarginX = 10;
    Sprite *scoreBoardBlack = Sprite::createWithSpriteFrameName("score_background.png");
    scoreBoardBlack->setPosition(Vec2(visibleSize.width/2 + origin.x - scoreBoardBlack->getContentSize().width / 2 - scoreBoardMarginX / 2, visibleSize.height + origin.y - settingItem->getContentSize().height - 20 - 20 - 20));
    
    Sprite* pieceBlack      = Sprite::createWithSpriteFrameName("black.png");
    pieceBlack->setPosition(Vec2(pieceBlack->getContentSize().width / 2 + 10, scoreBoardBlack->getContentSize().height / 2));
    scoreBoardBlack->addChild(pieceBlack);
    
    Label* labelBlack       = Label::createWithSystemFont("0", "Arial", 20);
    labelBlack->setPosition(Vec2(scoreBoardBlack->getContentSize().width - labelBlack->getContentSize().width / 2 - 10, scoreBoardBlack->getContentSize().height / 2));
    labelBlack->setColor(Color3B(0x20,0x22,0x23));
    scoreBoardBlack->addChild(labelBlack);
    
    this->scoreBoardControllerBlack = new ScoreBoardController(labelBlack, this->boardModel, Color::Black);

    this->addChild(scoreBoardBlack, 3);
    
    Sprite *scoreBoardWhite = Sprite::createWithSpriteFrameName("score_background.png");
    scoreBoardWhite->setPosition(Vec2(visibleSize.width/2 + origin.x + scoreBoardWhite->getContentSize().width / 2 + scoreBoardMarginX / 2, visibleSize.height + origin.y - settingItem->getContentSize().height - 20 - 20 - 20));
    this->addChild(scoreBoardWhite, 3);
    
    Sprite* pieceWhite      = Sprite::createWithSpriteFrameName("white.png");
    pieceWhite->setPosition(Vec2(pieceWhite->getContentSize().width / 2 + 10, scoreBoardWhite->getContentSize().height / 2));
    scoreBoardWhite->addChild(pieceWhite);

    Label* labelWhite       = Label::createWithSystemFont("0", "Arial", 20);
    labelWhite->setPosition(Vec2(scoreBoardWhite->getContentSize().width - labelWhite->getContentSize().width / 2 - 10, scoreBoardWhite->getContentSize().height / 2));
    labelWhite->setColor(Color3B(0xf8,0xf8,0xf8));
    scoreBoardWhite->addChild(labelWhite);
    
    this->scoreBoardControllerWhite = new ScoreBoardController(labelWhite, this->boardModel, Color::White);
    
    // create TurnController;
    this->turnController = new TurnController(playerBlack, playerWhite, this->boardController);
   
    this->schedule(schedule_selector(GameMain::update));
    
    return true;
}


void GameMain::update(float frame)
{
    this->turnController->update();
    this->scoreBoardControllerBlack->updateLabel();
    this->scoreBoardControllerWhite->updateLabel();
}


void GameMain::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void GameMain::onClickHomeButton(cocos2d::Ref *pSender)
{
    log("home button 押された");
    
    auto *scene = TitleScene::createScene();
    
    TransitionCrossFade* crossFade = TransitionCrossFade::create(0.5f, scene);
    
    Director::getInstance()->replaceScene(crossFade);
}

void GameMain::onClickSettingButton(cocos2d::Ref *pSender)
{
    log("setting button 押された");
}
