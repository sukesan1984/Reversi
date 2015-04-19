//
//  PieceControllersHolder.cpp
//  Reversi
//
//  Created by Kosuke Takami on 2015/04/19.
//
//

#include "PieceControllersHolder.h"

PieceControllersHolder::PieceControllersHolder(){}
PieceControllersHolder::PieceControllersHolder(PieceController **pieceControllers)
{
    this->pieceControllers = pieceControllers;
}

PieceControllersHolder::~PieceControllersHolder(){}

PieceController* PieceControllersHolder::get(int x, int y)
{
    int length = y * 8 + x;
    return this->pieceControllers[length];
}