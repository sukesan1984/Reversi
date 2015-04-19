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

class PieceController
{
public:
    enum PieceColor {
        Black = 1,
        White = 2,
    };
    PieceController();
    PieceController(cocos2d::Sprite *blackSprite, cocos2d::Sprite *whiteSprite, PieceColor defaultColor, cocos2d::Vec2 defaultPosition);
    ~PieceController();
    bool isShown = false;
    void changeColor();
    void show();
    void show(PieceColor color);
private:
    cocos2d::Sprite *blackSprite;
    cocos2d::Sprite *whiteSprite;
    cocos2d::Sprite *currentSprite;
    PieceColor currentColor;
    const float animationTime = 0.4f;
    bool isPlaying = false;
    cocos2d::Vec2 currentPosition;
    void setPosition(cocos2d::Vec2 position);
};

#endif /* defined(__Reversi__PieceController__) */
