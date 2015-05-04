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
#include "cocos2d.h"
#include "BoardModel.h"
#include "Const.h"

USING_NS_CC;

class ScoreBoardController
{
private:
    Label* scoreLabel;
    BoardModel* boardModel;
    Color color;
    
public:
    ScoreBoardController(Label* scoreLabel, BoardModel* boardModel, Color color);
    ~ScoreBoardController();
    
    void updateLabel();
};


#endif /* defined(__Reversi__ScoreBoardController__) */
