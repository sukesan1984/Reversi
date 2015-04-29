//
//  TurnController.cpp
//  Reversi
//
//  Created by Kosuke Takami on 2015/04/19.
//
//

#include "TurnController.h"

TurnController::TurnController(Player* playerBlack, Player* playerWhite, BoardController* boardController)
{
    this->currentTurn = Turn::Black;
    this->playerBlack = playerBlack;
    this->playerBlack->setOnSelectHandler(TouchDelegate<TurnController>::createDelegator(this, &TurnController::onSelectCell));
    this->playerWhite = playerWhite;
    this->playerWhite->setOnSelectHandler(TouchDelegate<TurnController>::createDelegator(this, &TurnController::onSelectCell));
    this->playerBlack->setTurn(true);
    
    this->boardController = boardController;
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
            this->playerBlack->setTurn(false);
            this->playerWhite->setTurn(true);
            break;
        case Turn::White:
            this->currentTurn = Turn::Black;
            this->playerWhite->setTurn(false);
            this->playerBlack->setTurn(true);
            break;
        default:
            break;
    }
    this->setPhase(Put);
}

void TurnController::onSelectCell(int x, int y)
{
    cocos2d::log("%d のターン: %d, %d", this->currentTurn, x, y);
    switch(this->currentTurn)
    {
        case Turn::Black:
            this->boardController->putPiece(x, y, Color::Black);
            break;
        case Turn::White:
            this->boardController->putPiece(x, y, Color::White);
            break;
        default:
            break;
    }
    this->setPhase(TurnEnd);
}

void TurnController::update()
{
    switch(this->currentPhase)
    {
        case Put:
            return;
            break;
        case Reverse:
            return;
            break;
        case TurnEnd:
            this->changeTurn();
            return;
            break;
        default:
            break;
    }
}

void TurnController::setPhase(TurnController::Phase phase)
{
    this->currentPhase = phase;
}