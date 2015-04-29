//
//  Player.h
//  Reversi
//
//  Created by Kosuke Takami on 2015/04/29.
//
//

#ifndef __Reversi__Player__
#define __Reversi__Player__

#include <stdio.h>
#include "Const.h"
#include "BoardController.h"

class Player
{
    BoardController* boardController;
    Color playerColor;
    bool isMyTurn = false;
public:
    Player(Color playerColor, BoardController* boardController);
    ~Player();
    void setTurn(bool isMyTurn);
    
    // boardControllerがタップされたときに呼ばれる。
    void onCellClick(int x, int y);
};

#endif /* defined(__Reversi__Player__) */
