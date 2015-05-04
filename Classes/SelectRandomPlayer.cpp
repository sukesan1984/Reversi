//
//  SelectRandomPlayer.cpp
//  Reversi
//
//  Created by Kosuke Takami on 2015/05/03.
//
//

#include "SelectRandomPlayer.h"
#include <math.h>

SelectRandomPlayer::SelectRandomPlayer(Color playerColor, BoardModel* boardModel) : NPCBase(playerColor, boardModel)
{
}

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
    
    this->put(point.x, point.y);
    
    return;
}

