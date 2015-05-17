//
//  SelectWithWeighting.cpp
//  Reversi
//
//  Created by Kosuke Takami on 2015/05/17.
//
//

#include "SelectWithWeighting.h"
#include <math.h>

SelectWithWeighting::SelectWithWeighting(Color playerColor, BoardModel* boardModel) : NPCBase(playerColor, boardModel)
{
    weighting = new int[8 * 8]{
        30 , -12,  0, -1, -1,  0, -12,  30,
        -12, -15, -3, -3, -3, -3, -15, -12,
        0  ,  -3,  0, -1, -1,  0,  -3,   0,
        -1 ,  -3, -1, -1, -1, -1,  -3,  -1,
        -1 ,  -3, -1, -1, -1, -1,  -3,  -1,
        0  ,  -3,  0, -1, -1,  0,  -3,   0,
        -12, -15, -3, -3, -3, -3, -15, -12,
        30 , -12,  0, -1, -1,  0, -12,  30
    };
}

void SelectWithWeighting::setTurn(bool isMyTurn)
{
    this->isMyTurn = isMyTurn;
    if(!this->isMyTurn)
    {
        return;
    }
    std::vector<Point> marked = this->boardModel->getMarked();
    
    std::vector<Point>::iterator it;
    int evaluation = 0;
    Point candidate;
    int count = 0;
    for(it = marked.begin(); it != marked.end(); ++it)
    {
        int currentEvaluation = this->boardModel->getEvaluation(it->x, it->y, this->playerColor, this->weighting);
        if(count == 0)
        {
            evaluation = currentEvaluation;
            candidate.x = it->x;
            candidate.y = it->y;
        }
        ///evaluationが最大となる位置を候補とする。
        else if(currentEvaluation > evaluation)
        {
            evaluation = currentEvaluation;
            candidate.x = it->x;
            candidate.y = it->y;
        }
        ///同じ値なら、相手が置ける位置が少ない方を優先する。
        else if(currentEvaluation == evaluation)
        {
            int puttableNum1 = this->boardModel->getNextPuttableNum(candidate.x, candidate.y, this->playerColor);
            int puttableNum2 = this->boardModel->getNextPuttableNum(it->x, it->y, this->playerColor);
            if(puttableNum1 > puttableNum2)
            {
                candidate.x = it->x;
                candidate.y = it->y;
            }
            else if(puttableNum1 == puttableNum2)
            {
                //それも同じ時は、確率で入れ替える
                if(rand()%2 == 0)
                {
                    candidate.x = it->x;
                    candidate.y = it->y;
                }
            }
        }
        count++;
    }
    
    this->put(candidate.x, candidate.y);
    return;
}