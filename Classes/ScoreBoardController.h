//
//  ScoreBoardController.h
//  Reversi
//
//  Created by Kosuke Takami on 2015/05/04.
//
//

#ifndef __Reversi__ScoreBoardController__
#define __Reversi__ScoreBoardController__

#include <stdio.h>
#include "BoardModel.h"
#include "cocos2d.h"

USING_NS_CC;

class ScoreBoardController
{
private:
    Sprite* scoreBoardBackground;
    Sprite* pieceSprite;
    
public:
    ScoreBoardController();
    ~ScoreBoardController();
};


#endif /* defined(__Reversi__ScoreBoardController__) */
