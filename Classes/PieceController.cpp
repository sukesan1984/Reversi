//
//  PieceController.cpp
//  Reversi
//
//  Created by Kosuke Takami on 2015/04/18.
//
//

#include "PieceController.h"

PieceController::PieceController(){}
PieceController::PieceController(cocos2d::Sprite *blackSprite, cocos2d::Sprite *whiteSprite, PieceColor defaultColor)
{
    this->blackSprite = blackSprite;
    this->whiteSprite = whiteSprite;
    this->currentColor = defaultColor;
    switch(this->currentColor)
    {
        case PieceColor::White:
            this->blackSprite->setScale(0.0f, 1.0f);
            break;
        case PieceColor::Black:
            this->whiteSprite->setScale(0.0f, 1.0f);
            break;
        default:
            break;
    }
}

PieceController::~PieceController(){}

void PieceController::ChangeColor()
{
    if(this->isPlaying) return;
    
    cocos2d::Sprite *currentSprite;
    cocos2d::Sprite *nextSprite;
    switch(this->currentColor)
    {
        case PieceColor::White:
            currentSprite = this->whiteSprite;
            nextSprite = this->blackSprite;
            this->currentColor = PieceColor::Black;
            break;
        case PieceColor::Black:
            currentSprite = this->blackSprite;
            nextSprite = this->whiteSprite;
            this->currentColor = PieceColor::White;
            break;
        default:
            break;
    }
    
    auto actionToZero = cocos2d::ScaleTo::create(this->animationTime/2, 0.0f, 1.0f);
    auto actionToOne  = cocos2d::ScaleTo::create(this->animationTime/2, 1.0f, 1.0f);
    auto actionDelay  = cocos2d::DelayTime::create(this->animationTime/2);
    
    this->isPlaying = true;
    currentSprite->runAction(actionToZero);
    cocos2d::CallFunc *callback = cocos2d::CallFunc::create([this](){
        this->isPlaying = false;
    });

    cocos2d::Sequence* waitToZero = cocos2d::Sequence::create(actionDelay, actionToOne, callback, NULL);
    
    cocos2d::Action *afterAction  = nextSprite->runAction(waitToZero);
    this->isPlaying = !afterAction->isDone();
}
