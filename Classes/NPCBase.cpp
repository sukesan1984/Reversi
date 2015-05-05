//
//  NPCBase.cpp
//  Reversi
//
//  Created by Kosuke Takami on 2015/05/04.
//
//

#include "NPCBase.h"

NPCBase::NPCBase(Color playerColor, BoardModel* boardModel)
{
    this->playerColor = playerColor;
    this->boardModel  = boardModel;
    this->isMyTurn    = false;
}

NPCBase::~NPCBase(){}

/// 自分のターンになったら
void NPCBase::setTurn(bool isMyTurn)
{
    this->isMyTurn = isMyTurn;
    if(!this->isMyTurn)
    {
        return;
    }
    
    return;
}

void NPCBase::setOnSelectHandler(DelegateBase *delegate)
{
    this->listeners.push_back(delegate);
}

void NPCBase::put(int x, int y)
{
    std::vector<DelegateBase*>::iterator it;
    
    for(it = this->listeners.begin(); it != this->listeners.end(); ++it)
    {
        (**it)(x, y);
    }
}