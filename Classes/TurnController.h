//
//  TurnController.h
//  Reversi
//
//  Created by Kosuke Takami on 2015/04/19.
//
//

#ifndef __Reversi__TurnController__
#define __Reversi__TurnController__

#include <stdio.h>

/// ターンを制御する奴
/// ターンは黒のターンと白のターンがある。
class TurnController{
public:
    enum Turn{
        Black = 1,
        White = 2
    };
    TurnController();
    ~TurnController();
    
    void changeTurn();
    Turn getCurrentTurn();
private:
    Turn currentTurn;
};

#endif /* defined(__Reversi__TurnController__) */
