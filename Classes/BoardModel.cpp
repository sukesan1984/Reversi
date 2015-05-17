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
    this->setState(3,3,Color::Black);
    this->setState(3,4,Color::White);
    this->setState(4,3,Color::White);
    this->setState(4,4,Color::Black);
}

BoardModel::BoardModel(State *boards)
{
    this->boards = new State[8 * 8];
    for(int i = 0; i < 8 * 8; i++)
    {
        this->boards[i] = boards[i];
    }
}

void BoardModel::changeColor(int x, int y)
{
    State currentState = this->getState(x, y);
    switch(currentState)
    {
        case State::Black:
            this->setState(x, y, Color::White);
            break;
        case State::White:
            this->setState(x, y, Color::Black);
            break;
        default:
            break;
    }
}

void BoardModel::reverse(int x, int y, Color color)
{
    switch(color)
    {
        case Color::White:
            this->reverse(x, y, State::White);
            break;
        case Color::Black:
            this->reverse(x, y, State::Black);
            break;
        default:
            break;
    }
}

void BoardModel::reverse(int x, int y, BoardModel::State state)
{
    if(state != State::Black && state != State::White) return;
    State targetState = (state == State::Black) ? State::White : State::Black;
    this->reverse(targetState, x - 1, y,     Direction::Left);
    this->reverse(targetState, x - 1, y + 1, Direction::LeftTop);
    this->reverse(targetState, x    , y + 1, Direction::Top);
    this->reverse(targetState, x + 1, y + 1, Direction::RightTop);
    this->reverse(targetState, x + 1, y    , Direction::Right);
    this->reverse(targetState, x + 1, y - 1, Direction::RightDown);
    this->reverse(targetState, x    , y - 1, Direction::Down);
    this->reverse(targetState, x - 1, y - 1, Direction::LeftDown);
}

bool BoardModel::isMarked(int x, int y)
{
    State state = this->getState(x, y);
    return state == State::Marked;
}

bool BoardModel::reverse(BoardModel::State state, int x, int y, BoardModel::Direction checkDirection)
{
    State targetState = (state == State::Black) ? State::White : State::Black;
    if(this->isEqualState(state, x, y))
    {
        switch(checkDirection)
        {
            case Direction::Right:
                if(this->reverse(state, x + 1, y, checkDirection))
                {
                    this->changeColor(x, y);
                    return true;
                }
                return false;
                break;
            case Direction::RightDown:
                if(this->reverse(state, x + 1, y - 1, checkDirection))
                {
                    this->changeColor(x, y);
                    return true;
                }
                return false;
                break;
            case Direction::Down:
                if(this->reverse(state, x    , y - 1, checkDirection))
                {
                    this->changeColor(x, y);
                    return true;
                }
                return false;
                break;
            case Direction::LeftDown:
                if(this->reverse(state, x - 1, y - 1, checkDirection))
                {
                    this->changeColor(x, y);
                    return true;
                }
                return false;
                break;
            case Direction::Left:
                if(this->reverse(state, x - 1, y,     checkDirection))
                {
                    this->changeColor(x, y);
                    return true;
                }
                return false;
                break;
            case Direction::LeftTop:
                if(this->reverse(state, x - 1, y + 1, checkDirection))
                {
                    this->changeColor(x, y);
                    return true;
                }
                return false;
                break;
            case Direction::Top:
                if(this->reverse(state, x    , y + 1, checkDirection))
                {
                    this->changeColor(x, y);
                    return true;
                }
                return false;
                break;
            case Direction::RightTop:
                if(this->reverse(state, x + 1, y + 1, checkDirection))
                {
                    this->changeColor(x, y);
                    return true;
                }
                return false;
                break;
            default:
                break;
        }
    }
    else if(this->isEqualState(targetState, x, y))
    {
        return true;
    }
    return false;
}

void BoardModel::setState(int x, int y, Color color)
{
    switch(color)
    {
        case Color::White:
            this->setState(x, y, State::White);
            break;
        case Color::Black:
            this->setState(x, y, State::Black);
            break;
        default:
            break;
    }
}

void BoardModel::setState(int x, int y, BoardModel::State state)
{
    int i = y * 8 + x;
    
    State currentState = this->getState(x, y);
    Color color = state == State::Black ? Color::Black :
                  state == State::White ? Color::White :
                           Color::None;
    switch(currentState)
    {
        case State::None:
        case State::Marked:
            this->increaseNum(color);
            break;
        case State::Black:
            if(color == Color::Black)
            {
                return;
            }
            this->increaseNum(Color::White);
            this->decreaseNum(Color::Black);
            
            break;
        case State::White:
            if(color == Color::White)
            {
                return;
            }
            this->increaseNum(Color::Black);
            this->decreaseNum(Color::White);
            
            break;
        default:
            break;
    }
    this->boards[i] = state;
}

std::vector<Point> BoardModel::getMarked()
{
    std::vector<Point> marked;
    for(int i = 0; i < 8 * 8; i++)
    {
        if(this->boards[i] == State::Marked)
        {
            Point point;
            point.x = i % 8;
            point.y = i / 8;
            
            marked.push_back(point);
        }
    }
    return marked;
}

void BoardModel::showNum()
{
    cocos2d::log("black: %d", this->blackNum);
    cocos2d::log("white: %d", this->whiteNum);
}

int BoardModel::getNum(Color color)
{
    switch(color)
    {
        case Color::Black:
            return this->blackNum;
            break;
        case Color::White:
            return this->whiteNum;
            break;
        default:
            return 0;
            break;
    }
}

int BoardModel::getNextPuttableNum(int x, int y, Color color)
{
    BoardModel *copied = this->getCopied();
    
    copied->setState(x, y, color);
    copied->reverse(x, y, color);
    
    Color nextColor = color == Color::Black ? Color::White :
                    color == Color::White ? Color::Black :
                    Color::None;
    copied->setMarked(nextColor);
    int count =  (int) copied->getMarked().size();
    
    return count;
}

int BoardModel::getEvaluation(int x, int y, Color color, int *weighting)
{
    BoardModel * copied = this->getCopied();
    
    copied->setState(x, y, color);
    copied->reverse(x, y, color);
    
    int evaluation = 0;
    for(int i = 0; i < 8 * 8; i++)
    {
        int x = i % 8;
        int y = i / 8;
        State state = copied->getState(x, y);
        
        //黒を基準に考える
        switch(state)
        {
            case State::Black:
                evaluation += weighting[i]; //黒があれば、黒の点数をプラスする。
                break;
            case State::White:
                evaluation -= weighting[i]; //白があれば、その位置の点数をマイナスする。
                break;
            default:
                break;
        }
    }
    
    if(color == Color::Black)
    {
        return evaluation;
    }
    
    return -evaluation;
}


void BoardModel::setMarked(Color color)
{
    switch(color)
    {
        case Color::White:
            this->setMarked(State::White);
            break;
        case Color::Black:
            this->setMarked(State::Black);
            break;
        default:
            break;
    }
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

bool BoardModel::hasPuttablePlace()
{
    int markedPlace = 0;
    for(int i = 0; i < 8 * 8; i++)
    {
        if(this->boards[i] == State::Marked)
        {
            markedPlace++;
        }
    }
    return markedPlace > 0;
}

void BoardModel::increaseNum(Color color)
{
    this->changeNum(color, 1);
}

void BoardModel::decreaseNum(Color color)
{
    this->changeNum(color, -1);
}

void BoardModel::changeNum(Color color, int num)
{
    switch(color)
    {
        case Color::White:
            this->whiteNum += num;
            break;
        case Color::Black:
            this->blackNum += num;
            break;
        default:
            break;
    }
}

BoardModel* BoardModel::getCopied()
{
    return new BoardModel(this->boards);
}

