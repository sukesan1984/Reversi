//
//  PieceControllersHolder.h
//  Reversi
//
//  Created by Kosuke Takami on 2015/04/19.
//
//

#ifndef __Reversi__PieceControllersHolder__
#define __Reversi__PieceControllersHolder__

#include <stdio.h>
#include "PieceController.h"

class PieceControllersHolder
{
private:
    PieceController **pieceControllers;
public:
    PieceControllersHolder();
    PieceControllersHolder(PieceController **pieceControllers);
    ~PieceControllersHolder();
    PieceController* get(int x, int y);
};

#endif /* defined(__Reversi__PieceControllersHolder__) */