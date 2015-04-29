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
#include "TouchDelegate.h"

/// ターンを制御する奴
/// ターンは黒のターンと白のターンがある。
class TurnController{
public:
    enum Turn{
        Black = 1,
        White = 2
    };
    ///フェーズ
    enum Phase {
        Put     = 1, ///オセロを置く
        Reverse = 2, ///オセロをひっくりがえす
        TurnEnd = 3, ///終了
    };
    
    TurnController(Player* playerBlack, Player* playerWhite);
    ~TurnController();
    
    void changeTurn();
    Turn getCurrentTurn();
    ///PlayerがCellを選択したときに呼ばれる。
    void onSelectCell(int x, int y);
    void update();
private:
    Turn currentTurn;
    Player* playerBlack;
    Player* playerWhite;
    
    Phase currentPhase = Put;
    
    void setPhase(Phase phase);
};

#endif /* defined(__Reversi__TurnController__) */