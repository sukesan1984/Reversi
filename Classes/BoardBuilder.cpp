//
//  BoardBuilder.cpp
//  Reversi
//
//  Created by Kosuke Takami on 2015/04/19.
//
//

#include "BoardBuilder.h"

BoardBuilder::BoardBuilder(){}
BoardBuilder::BoardBuilder(cocos2d::Layer *parentLayer, cocos2d::EventDispatcher* eventDispatcher)
{
    this->parentLayer = parentLayer;
    this->eventDispatcher = eventDispatcher;
}
BoardBuilder::~BoardBuilder(){}

void BoardBuilder::create(cocos2d::Vec2 centerPos)
{
    this->pieceControllers = this->createPieceControllers();
    this->pieceControllersHolder = new PieceControllersHolder(pieceControllers);
    
    /// boardのview生成
    cocos2d::Sprite *boardSprite = cocos2d::Sprite::createWithSpriteFrameName("board.png");
    boardSprite->setPosition(centerPos);
    this->parentLayer->addChild(boardSprite, 2);
    
    /// BoardControllerの生成
    this->boardController = new BoardController(boardSprite, this->pieceControllersHolder, this->eventDispatcher);
}

PieceController** BoardBuilder::createPieceControllers()
{
    const int Width  = 8;
    const int Height = 8;
    int Length = Width * Height;
    PieceController **pieceControllers = new PieceController*[Length];
    
    for(int i = 0; i < Length; i++) {
        int x = i % Width;
        int y = i / Width;
        cocos2d::Sprite *blackSprite = cocos2d::Sprite::createWithSpriteFrameName("black.png");
        cocos2d::Sprite *whiteSprite = cocos2d::Sprite::createWithSpriteFrameName("white.png");
        pieceControllers[i] = new PieceController(
                                         blackSprite,
                                         whiteSprite,
                                         PieceController::PieceColor::White,
                                                  cocos2d::Vec2(blackSprite->getContentSize().width * x, blackSprite->getContentSize().height * y));
        
        this->parentLayer->addChild(blackSprite, 3);
        this->parentLayer->addChild(whiteSprite, 3);
    }
    
    return pieceControllers;
}