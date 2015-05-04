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
#include "BoardModel.h"
#include "NPCBase.h"

class SelectRandomPlayer : public NPCBase
{
public:
    SelectRandomPlayer(Color playerColor, BoardModel* boardModel);
    void setTurn(bool isMyTurn);
};

#endif /* defined(__Reversi__SelectRandomPlayer__) */
