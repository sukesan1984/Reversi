//
//  NPCBase.h
//  Reversi
//
//  Created by Kosuke Takami on 2015/05/04.
//
//

#ifndef __Reversi__NPCBase__
#define __Reversi__NPCBase__

#include <stdio.h>
#include "IPlayer.h"
#include "Const.h"
#include "BoardModel.h"

class NPCBase : public IPlayer
{
protected:
    Color playerColor;
    BoardModel* boardModel;
    bool isMyTurn;
    std::vector<DelegateBase*> listeners;
    void put(int x, int y);
public:
    NPCBase(Color playerColor, BoardModel* boardModel);
    ~NPCBase();
    
    virtual void setTurn(bool isMyTurn);
    void setOnSelectHandler(DelegateBase* delegate);
};

#endif /* defined(__Reversi__NPCBase__) */
