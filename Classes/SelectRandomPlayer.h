//
//  SelectRandomPlayer.h
//  Reversi
//
//  Created by Kosuke Takami on 2015/05/03.
//
//

#ifndef __Reversi__SelectRandomPlayer__
#define __Reversi__SelectRandomPlayer__

#include <stdio.h>
#include "Const.h"
#include "IPlayer.h"
#include "BoardModel.h"

class SelectRandomPlayer : public IPlayer
{
private:
    Color playerColor;
    BoardModel* boardModel;
    bool isMyTurn;
    std::vector<DelegateBase*> listeners;
public:
    SelectRandomPlayer(Color playerColor, BoardModel* boardModel);
    ~SelectRandomPlayer();

    void setTurn(bool isMyTurn);
    void setOnSelectHandler(DelegateBase* delegate);
};

#endif /* defined(__Reversi__SelectRandomPlayer__) */
