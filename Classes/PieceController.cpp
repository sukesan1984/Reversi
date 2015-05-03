//
//  PieceController.cpp
//  Reversi
//
//  Created by Kosuke Takami on 2015/04/18.
//
//

#include "PieceController.h"

PieceController::PieceController(){}
PieceController::PieceController(cocos2d::Sprite *blackSprite, cocos2d::Sprite *whiteSprite, Color defaultColor, cocos2d::Vec2 defaultPosition)
{
    this->blackSprite     = blackSprite;
    this->blackSprite->setOpacity(0);
    this->whiteSprite     = whiteSprite;
    this->whiteSprite->setOpacity(0);
    this->currentColor    = defaultColor;
    this->currentPosition = defaultPosition;
    this->setPosition(defaultPosition);
    switch(this->currentColor)
    {
        case Color::White:
            this->blackSprite->setScale(0.0f, 1.0f);
            break;
        case Color::Black:
            this->whiteSprite->setScale(0.0f, 1.0f);
            break;
        default:
            break;
    }
}

PieceController::~PieceController(){}

void PieceController::changeColor(cocos2d::CallFunc* callback)
{
    if(this->isPlaying){
        callback->execute();
        return;
    }
    
    cocos2d::Sprite *currentSprite;
    cocos2d::Sprite *nextSprite;
    switch(this->currentColor)
    {
        case Color::White:
            currentSprite = this->whiteSprite;
            nextSprite = this->blackSprite;
            this->currentColor = Color::Black;
            break;
        case Color::Black:
            currentSprite = this->blackSprite;
            nextSprite = this->whiteSprite;
            this->currentColor = Color::White;
            break;
        default:
            break;
    }
    
    auto actionToZero = cocos2d::ScaleTo::create(this->animationTime/2, 0.0f, 1.0f);
    auto actionToOne  = cocos2d::ScaleTo::create(this->animationTime/2, 1.0f, 1.0f);
    auto actionDelay  = cocos2d::DelayTime::create(this->animationTime/2);
    
    this->isPlaying = true;
    currentSprite->runAction(actionToZero);
    cocos2d::CallFunc *callback0 = cocos2d::CallFunc::create([this](){
        this->isPlaying = false;
    });

    cocos2d::Sequence* waitToZero = cocos2d::Sequence::create(actionDelay, actionToOne, callback0, callback, NULL);
    
    cocos2d::Action *afterAction  = nextSprite->runAction(waitToZero);
    this->isPlaying = !afterAction->isDone();
}

void PieceController::changeColor(Color color, cocos2d::CallFunc *callback)
{
    if(this->currentColor == color) {
        callback->execute();
        return;
    }
    this->changeColor(callback);
}

void PieceController::show()
{
    if(this->isPlaying) return;
    this->isPlaying = true;
    auto action0 = cocos2d::FadeIn::create(0.1f);
    cocos2d::CallFunc *callback0 = cocos2d::CallFunc::create([this](){
        this->isPlaying = false;
    });
    cocos2d::Sequence *sequence0 = cocos2d::Sequence::create(action0, callback0, NULL);
    
    auto action1 = cocos2d::FadeIn::create(0.1f);
    cocos2d::CallFunc *callback1 = cocos2d::CallFunc::create([this](){
        this->isPlaying = false;
        this->isShown = true;
    });
    cocos2d::Sequence *sequence1 = cocos2d::Sequence::create(action1, callback1, NULL);
    this->blackSprite->runAction(sequence0);
    this->whiteSprite->runAction(sequence1);
}

void PieceController::show(Color color)
{
    if(this->currentColor == color)
    {
        this->show();
    }
    else
    {
        this->currentColor    = color;
        switch(this->currentColor)
        {
            case Color::White:
                this->blackSprite->setScale(0.0f, 1.0f);
                this->whiteSprite->setScale(1.0f, 1.0f);
                break;
            case Color::Black:
                this->whiteSprite->setScale(0.0f, 1.0f);
                this->blackSprite->setScale(1.0f, 1.0f);
                break;
            default:
                break;
        }
        this->show();
    }
}

void PieceController::show(BoardModel::State state)
{
    if(state != BoardModel::State::None)
    {
        switch(state)
        {
            case BoardModel::State::Black:
                this->show(Color::Black);
                break;
            case BoardModel::State::White:
                this->show(Color::White);
                break;
            default:
                break;
        }
    }
}

void PieceController::setPosition(cocos2d::Vec2 position)
{
    this->blackSprite->setPosition(position);
    this->whiteSprite->setPosition(position);
}