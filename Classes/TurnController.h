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
#include "Player.h"

/// ターンを制御する奴
/// ターンは黒のターンと白のターンがある。
class TurnController{
public:
    enum Turn{
        Black = 1,
        White = 2
    };
    TurnController(Player* playerBlack, Player* playerWhite);
    ~TurnController();
    
    void changeTurn();
    Turn getCurrentTurn();
    ///PlayerがCellを選択したときに呼ばれる。
    void onSelectCell(int x, int y, Player* player);
private:
    Turn currentTurn;
    Player* playerBlack;
    Player* playerWhite;
    
};

#endif /* defined(__Reversi__TurnController__) */