//
//  MarkController.cpp
//  Reversi
//
//  Created by Kosuke Takami on 2015/04/19.
//
//

#include "MarkController.h"

MarkController::MarkController(cocos2d::Sprite *markSprite, cocos2d::Vec2 defaultPosition)
{
    this->markSprite = markSprite;
    this->currentPosition = defaultPosition;
    this->markSprite->setOpacity(0);
    this->markSprite->setPosition(this->currentPosition);
}

MarkController::MarkController(){}
MarkController::~MarkController(){}

void MarkController::show()
{
    this->markSprite->setOpacity(255);
}
void MarkController::hide()
{
    this->markSprite->setOpacity(0);
}