//
//  BoardBuilder.cpp
//  Reversi
//
//  Created by Kosuke Takami on 2015/04/19.
//
//

#include "BoardBuilder.h"

BoardBuilder::BoardBuilder(){}
BoardBuilder::BoardBuilder(cocos2d::Layer *parentLayer, cocos2d::EventDispatcher* eventDispatcher, TurnController* turnController)
{
    this->parentLayer = parentLayer;
    this->eventDispatcher = eventDispatcher;
    this->turnController = turnController;
}
BoardBuilder::~BoardBuilder(){}

void BoardBuilder::create(cocos2d::Vec2 centerPos)
{
    
    /// boardのview生成
    this->boardSprite = cocos2d::Sprite::createWithSpriteFrameName("board.png");
    boardSprite->setPosition(centerPos);
    this->parentLayer->addChild(boardSprite, 2);
    
    /// 駒達を作る
    this->pieceControllers = this->createPieceControllers(centerPos);
    this->pieceControllersHolder = new PieceControllersHolder(pieceControllers);
    
    
    this->boardModel = new BoardModel();
    
    /// BoardControllerの生成
    this->boardController = new BoardController(boardSprite, this->pieceControllersHolder, this->boardModel, this->eventDispatcher, this->turnController);
}

PieceController** BoardBuilder::createPieceControllers(cocos2d::Vec2 centerPos)
{
    const int Width  = 8;
    const int Height = 8;
    int Length = Width * Height;
    PieceController **pieceControllers = new PieceController*[Length];
    this->pieceSprites = new cocos2d::Sprite*[Width * Height * 2]; //数 * 2 (black white)
    
    float width = this->boardSprite->getContentSize().width / (float) Width;
    float height = this->boardSprite->getContentSize().height / (float) Height;
    
    for(int i = 0; i < Length; i++) {
        int x = i % Width;
        int y = i / Width;
        cocos2d::Sprite *blackSprite = cocos2d::Sprite::createWithSpriteFrameName("black.png");
        cocos2d::Sprite *whiteSprite = cocos2d::Sprite::createWithSpriteFrameName("white.png");
        this->pieceSprites[2 * i] = blackSprite;
        this->pieceSprites[2 * i + 1] = whiteSprite;
        pieceControllers[i] = new PieceController(
                                         blackSprite,
                                         whiteSprite,
                                         PieceController::PieceColor::White,
                                                  cocos2d::Vec2(centerPos.x - this->boardSprite->getContentSize().width / 2 + width * x + width / 2,
                                                                centerPos.y - this->boardSprite->getContentSize().height / 2 + height * y + height / 2));
        
        this->parentLayer->addChild(blackSprite, 3);
        this->parentLayer->addChild(whiteSprite, 3);
    }
    
    return pieceControllers;
}