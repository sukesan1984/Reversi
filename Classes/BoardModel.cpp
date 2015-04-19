//
//  BoardModel.cpp
//  Reversi
//
//  Created by Kosuke Takami on 2015/04/19.
//
//

#include "BoardModel.h"

BoardModel::BoardModel()
{
    //初期化
    this->boards = new State[8 * 8];
    for(int i = 0; i < 8 * 8; i++)
    {
        this->boards[i] = State::None;
    };
    this->setState(3,3,State::Black);
    this->setState(3,4,State::White);
    this->setState(4,3,State::White);
    this->setState(4,4,State::Black);
}

void BoardModel::setState(int x, int y, BoardModel::State state)
{
    int i = y * 8 + x;
    this->boards[i] = state;
}

BoardModel::State BoardModel::getState(int x, int y)
{
    int i = y * 8 + x;
    return this->boards[i];
}

BoardModel::~BoardModel(){}