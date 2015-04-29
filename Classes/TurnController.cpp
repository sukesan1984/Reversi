//
//  TurnController.cpp
//  Reversi
//
//  Created by Kosuke Takami on 2015/04/19.
//
//

#include "TurnController.h"

TurnController::TurnController(Player* playerBlack, Player* playerWhite)
{
    this->currentTurn = Turn::Black;
    this->playerBlack = playerBlack;
    this->playerWhite = playerWhite;
}

TurnController::~TurnController(){}

TurnController::Turn TurnController::getCurrentTurn()
{
    return this->currentTurn;
}

void TurnController::changeTurn()
{
    switch(this->currentTurn)
    {
        case Turn::Black:
            this->currentTurn = Turn::White;
            break;
        case Turn::White:
            this->currentTurn = Turn::Black;
            break;
        default:
            break;
    }
}