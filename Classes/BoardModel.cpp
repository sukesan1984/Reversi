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

void BoardModel::changeColor(int x, int y)
{
    State currentState = this->getState(x, y);
    switch(currentState)
    {
        case State::Black:
            this->setState(x, y, State::White);
            break;
        case State::White:
            this->setState(x, y, State::Black);
            break;
        default:
            break;
    }
}

void BoardModel::setState(int x, int y, BoardModel::State state)
{
    int i = y * 8 + x;
    this->boards[i] = state;
}

void BoardModel::setMarked(State state)
{
    //全部チェックする
    for(int i = 0; i < 8 * 8; i++)
    {
        int x = i % 8;
        int y = i / 8;
        State targetState = this->getState(x, y);
        switch(targetState)
        {
            case State::None:
            case State::Marked:
                continue;
                break;
            case State::Black:
            case State::White:
                if(state == targetState){
                    continue;
                }
                break;
            default:
                break;
        }
        if(this->isEqualState(state, x - 1, y))     this->setMarked(state, x + 1, y    , Direction::Right);
        if(this->isEqualState(state, x - 1, y + 1)) this->setMarked(state, x + 1, y - 1, Direction::RightDown);
        if(this->isEqualState(state, x    , y + 1)) this->setMarked(state, x    , y - 1, Direction::Down);
        if(this->isEqualState(state, x + 1, y + 1)) this->setMarked(state, x - 1, y - 1, Direction::LeftDown);
        if(this->isEqualState(state, x + 1, y))     this->setMarked(state, x - 1, y    , Direction::Left);
        if(this->isEqualState(state, x + 1, y - 1)) this->setMarked(state, x - 1, y + 1, Direction::LeftTop);
        if(this->isEqualState(state, x    , y - 1)) this->setMarked(state, x    , y + 1, Direction::Top);
        if(this->isEqualState(state, x - 1, y - 1)) this->setMarked(state, x + 1, y + 1, Direction::RightTop);
    }
    
    for(int i = 0; i < 8 * 8; i++)
    {
        int x = i % 8;
        int y = i / 8;
        
        cocos2d::log("x:%d, y: %d, state:%d", x, y, (int) this->boards[i]);
    }
}

void BoardModel::setMarked(BoardModel::State state, int x, int y, BoardModel::Direction checkDirection)
{
    if(x < 0) return;
    if(y < 0) return;
    if(x >= 8) return;
    if(y >= 8) return;
    State targetState = this->getState(x, y);
    if(targetState == state) return;
    if(targetState == State::None)
    {
        this->setState(x, y, State::Marked);
        return;
    }
    if(targetState == State::Marked) return;
    
    //隣と同じ色の時はさらに進める
    switch(checkDirection)
    {
        case Direction::Right:
            this->setMarked(state, x + 1, y, checkDirection);
            break;
        case Direction::RightDown:
            this->setMarked(state, x + 1, y - 1, checkDirection);
            break;
        case Direction::Down:
            this->setMarked(state, x    , y - 1, checkDirection);
            break;
        case Direction::LeftDown:
            this->setMarked(state, x - 1, y - 1, checkDirection);
            break;
        case Direction::Left:
            this->setMarked(state, x - 1, y    , checkDirection);
            break;
        case Direction::LeftTop:
            this->setMarked(state, x - 1, y + 1, checkDirection);
            break;
        case Direction::Top:
            this->setMarked(state, x    , y + 1, checkDirection);
            break;
        case Direction::RightTop:
            this->setMarked(state, x + 1, y + 1, checkDirection);
            break;
        default:
            break;
    }
}

void BoardModel::removeMarked()
{
    for(int i = 0; i < 8 * 8; i++)
    {
        int x = i % 8;
        int y = i / 8;
        if(this->boards[i] == State::Marked) this->setState(x, y, BoardModel::None);
    }
}

BoardModel::State BoardModel::getState(int x, int y)
{
    int i = y * 8 + x;
    return this->boards[i];
}

bool BoardModel::isEqualState(BoardModel::State state, int x, int y)
{
    if(x < 0) return false;
    if(y < 0) return false;
    if(x >= 8) return false;
    if(y >= 8) return false;
    
    return this->getState(x, y) == state;
}

BoardModel::~BoardModel(){}