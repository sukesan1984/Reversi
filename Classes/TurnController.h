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
#include "IPlayer.h"
#include "TouchDelegate.h"
#include "BoardController.h"

/// ターンを制御する奴
/// ターンは黒のターンと白のターンがある。
class TurnController{
public:
    ///フェーズ
    enum Phase {
        SetMark         = 0, /// オセロを置ける位置をマークする
        SearchPuttable  = 1, ///オセロを置ける位置を探す
        Put     = 2, ///オセロを置く
        Reverse = 3, ///オセロをひっくりがえす
        TurnEnd = 4, ///終了
    };
    
    TurnController(IPlayer* playerBlack, IPlayer* playerWhite, BoardController* boardController);
    ~TurnController();
    
    void setTurn();
    void changeTurn();
    Color getCurrentTurn();
    ///PlayerがCellを選択したときに呼ばれる。
    void onSelectCell(int x, int y);
    void update();
private:
    Color currentTurn;
    IPlayer* playerBlack;
    IPlayer* playerWhite;
    
    BoardController *boardController;
    
    Phase currentPhase = SearchPuttable;
    
    void setPhase(Phase phase);
};

#endif /* defined(__Reversi__TurnController__) */