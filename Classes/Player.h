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
#include <vector>
#include "IPlayer.h"
#include "DelegateBase.h"

class Player : public IPlayer
{
    Color playerColor;
    bool isMyTurn = false;
    std::vector<DelegateBase*> listeners;
public:
    Player(Color playerColor);
    ~Player();
    void setTurn(bool isMyTurn);
    
    // boardControllerがタップされたときに呼ばれる。
    void onCellClick(int x, int y);
    
    void setOnSelectHandler(DelegateBase* delegate);
};

#endif /* defined(__Reversi__Player__) */
