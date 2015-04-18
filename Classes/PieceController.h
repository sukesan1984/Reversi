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
    PieceController(cocos2d::Sprite *blackSprite, cocos2d::Sprite *whiteSprite, PieceColor defaultColor);
    ~PieceController();
    
    void ChangeColor();
private:
    cocos2d::Sprite *blackSprite;
    cocos2d::Sprite *whiteSprite;
    PieceColor currentColor;
    const float animationTime = 0.4f;
    bool isPlaying = false;
};

#endif /* defined(__Reversi__PieceController__) */
