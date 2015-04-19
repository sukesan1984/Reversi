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
    cocos2d::Sprite *boardSprite = cocos2d::Sprite::createWithSpriteFrameName("board.png");
    boardSprite->setPosition(centerPos);
    this->parentLayer->addChild(boardSprite, 2);
    
    BoardController* boardController = new BoardController(boardSprite, eventDispatcher);
}