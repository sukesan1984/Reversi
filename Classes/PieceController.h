//
//  PieceController.h
//  Reversi
//
//  Created by Kosuke Takami on 2015/04/18.
//
//

#ifndef __Reversi__PieceController__
#define __Reversi__PieceController__

#include <stdio.h>
#include "cocos2d.h"
#include "BoardModel.h"
#include "Const.h"

class PieceController
{
public:
    PieceController();
    PieceController(cocos2d::Sprite *blackSprite, cocos2d::Sprite *whiteSprite, Color defaultColor, cocos2d::Vec2 defaultPosition);
    ~PieceController();
    bool isShown = false;
    void changeColor(Color color, cocos2d::CallFunc* callback);
    void show();
    void show(Color color);
    void show(BoardModel::State state);
private:
    cocos2d::Sprite *blackSprite;
    cocos2d::Sprite *whiteSprite;
    cocos2d::Sprite *currentSprite;
    Color currentColor;
    const float animationTime = 0.4f;
    bool isPlaying = false;
    cocos2d::Vec2 currentPosition;
    void changeColor(cocos2d::CallFunc* callback);
    void setPosition(cocos2d::Vec2 position);
};

#endif /* defined(__Reversi__PieceController__) */
