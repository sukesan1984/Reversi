//
//  BoardModel.h
//  Reversi
//
//  Created by Kosuke Takami on 2015/04/19.
//
//

#ifndef __Reversi__BoardModel__
#define __Reversi__BoardModel__

#include <stdio.h>
#include <vector>
#include "Const.h"

/////////////////////////////////
///ボードの状態を保持する
/////////////////////////////////

class BoardModel
{
public:
    enum State{
        None  =   1,
        Black =   2,
        White =   3,
        Marked =  4, //置ける位置にマークされた状態
    };
    BoardModel();
    BoardModel(State *boards);
    ~BoardModel();
    
    State getState(int x, int y);
    void setMarked(Color color);
    std::vector<Point> getMarked();
    void setState(int x, int y, Color color);
    void removeMarked();
    void changeColor(int x, int y);
    void reverse(int x, int y, Color color);
    bool isMarked(int x, int y);
    bool hasPuttablePlace();
    void showNum();
    int getNum(Color color);
    
    //そのいちにcolorの石を置くと次の手番で何個置けるか
    int getNextPuttableNum(int x, int y, Color color);
private:

    enum Direction{
        Left      = 1,
        LeftTop   = 2,
        Top       = 3,
        RightTop  = 4,
        Right     = 5,
        RightDown = 6,
        Down      = 7,
        LeftDown  = 8,
    };
    State *boards;
    void setMarked(State state);
    void setState(int x, int y, State state);
    void setMarked(State state, int x, int y, Direction checkDirection);
    void setMarked(Color color, int x, int y, Direction checkDirection);
    void reverse(int x, int y, State state);
    bool reverse(State state,   int x, int y, Direction checkDirection);
    bool reverse(Color color,   int x, int y, Direction checkDirection);
    bool isEqualState(State state, int x, int y);
    
    void increaseNum(Color color);
    void decreaseNum(Color color);
    void changeNum(Color color, int num);
    
    BoardModel* getCopied();
    
    int whiteNum = 0;
    int blackNum = 0;
};

#endif /* defined(__Reversi__BoardModel__) */