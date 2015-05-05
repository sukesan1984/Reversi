//
//  SelectMakeOponentFewPlacesPlayer.cpp
//  Reversi
//
//  Created by Kosuke Takami on 2015/05/04.
//
//

#include "SelectMakeOponentFewPlacesPlayer.h"

SelectMakeOponentFewPlacesPlayer::SelectMakeOponentFewPlacesPlayer(Color playerColor, BoardModel* boardModel) : NPCBase(playerColor, boardModel)
{
}

void SelectMakeOponentFewPlacesPlayer::setTurn(bool isMyTurn)
{
    this->isMyTurn = isMyTurn;
    if(!this->isMyTurn)
    {
        return;
    }
    std::vector<Point> marked = this->boardModel->getMarked();
    
    std::vector<Point>::iterator it;
    int count = 64; //盤面の数
    Point candidate;
    for(it = marked.begin(); it != marked.end(); ++it)
    {
        int nextCount = this->boardModel->getNextPuttableNum(it->x, it->y, this->playerColor);
        cocos2d::log("next:%d", nextCount);
        if(nextCount < count);
        {
            candidate.x = it->x;
            cocos2d::log("x:%d", it->x);
            candidate.y = it->y;
            cocos2d::log("y:%d", it->y);
            count = nextCount;
        }
    }
    
    this->put(candidate.x, candidate.y);
    return;
}