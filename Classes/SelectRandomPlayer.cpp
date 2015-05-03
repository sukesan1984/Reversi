//
//  SelectRandomPlayer.cpp
//  Reversi
//
//  Created by Kosuke Takami on 2015/05/03.
//
//

#include "SelectRandomPlayer.h"
#include <math.h>

SelectRandomPlayer::SelectRandomPlayer(Color playerColor, BoardModel* boardModel)
{
    this->playerColor = playerColor;
    this->boardModel  = boardModel;
    this->isMyTurn    = false;
}

SelectRandomPlayer::~SelectRandomPlayer(){}

/// 自分のターンになったら
void SelectRandomPlayer::setTurn(bool isMyTurn)
{
    this->isMyTurn = isMyTurn;
    if(!this->isMyTurn)
    {
        return;
    }
    std::vector<Point> marked = this->boardModel->getMarked();
    
    Point point = marked[rand()%marked.size()];
    std::vector<DelegateBase*>::iterator it;
    
    for(it = this->listeners.begin(); it != this->listeners.end(); ++it)
    {
        (**it)(point.x, point.y);
    }
    
    return;
}

void SelectRandomPlayer::setOnSelectHandler(DelegateBase *delegate)
{
    this->listeners.push_back(delegate);
}