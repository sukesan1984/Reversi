//
//  TurnController.cpp
//  Reversi
//
//  Created by Kosuke Takami on 2015/04/19.
//
//

#include "TurnController.h"

TurnController::TurnController(IPlayer* playerBlack, IPlayer* playerWhite, BoardController* boardController)
{
    this->currentTurn = Color::Black;
    this->playerBlack = playerBlack;
    this->playerBlack->setOnSelectHandler(TouchDelegate<TurnController>::createDelegator(this, &TurnController::onSelectCell));
    this->playerWhite = playerWhite;
    this->playerWhite->setOnSelectHandler(TouchDelegate<TurnController>::createDelegator(this, &TurnController::onSelectCell));
    this->playerBlack->setTurn(true);
    
    this->boardController = boardController;
}

TurnController::~TurnController(){}

Color TurnController::getCurrentTurn()
{
    return this->currentTurn;
}

void TurnController::setTurn()
{
    switch(this->currentTurn)
    {
        case Color::Black:
            this->playerBlack->setTurn(true);
            break;
        case Color::White:
            this->playerWhite->setTurn(true);
            break;
        default:
            break;
    }
}

void TurnController::changeTurn()
{
    switch(this->currentTurn)
    {
        case Color::Black:
            this->currentTurn = Color::White;
            this->playerBlack->setTurn(false);
            break;
        case Color::White:
            this->currentTurn = Color::Black;
            this->playerWhite->setTurn(false);
            break;
        default:
            break;
    }
    this->setPhase(SetMark);
}

void TurnController::onSelectCell(int x, int y)
{
    cocos2d::log("%d のターン: %d, %d", this->currentTurn, x, y);
    bool canPut;
    if(this->currentPhase != Put)
    {
        return;
    }
    switch(this->currentTurn)
    {
        case Color::Black:
            canPut = this->boardController->putPiece(x, y, Color::Black);
            break;
        case Color::White:
            canPut = this->boardController->putPiece(x, y, Color::White);
            break;
        default:
            break;
    }
    if(canPut)
    {
        this->setPhase(TurnEnd);
    }
}

void TurnController::update()
{
    switch(this->currentPhase)
    {
        case SetMark:
            if(this->boardController->isPlaying())
                return;
            this->boardController->setMark(this->currentTurn);
            this->setPhase(SearchPuttable);
            break;
        case SearchPuttable:
            if(this->boardController->hasPuttablePlace())
            {
                this->setPhase(Put);
            }
            else
            {
                this->setPhase(TurnEnd);
            }
            break;
        case Put:
            this->setTurn();
            return;
            break;
        case Reverse:
            return;
            break;
        case TurnEnd:
            this->boardController->removeMark();
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