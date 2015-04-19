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

/////////////////////////////////
///ボードの状態を保持する
/////////////////////////////////

class BoardModel
{
public:
    enum State{
        None  = 1,
        Black = 2,
        White = 3
    };
    BoardModel();
    ~BoardModel();
    State getState(int x, int y);
private:
    State *boards;
    void setState(int x, int y, State state);
};

#endif /* defined(__Reversi__BoardModel__) */
