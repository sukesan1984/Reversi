//
//  ScoreBoardController.cpp
//  Reversi
//
//  Created by Kosuke Takami on 2015/05/04.
//
//

#include "ScoreBoardController.h"

ScoreBoardController::ScoreBoardController(Label* scoreLabel, BoardModel* boardModel, Color color)
{
    this->scoreLabel = scoreLabel;
    this->boardModel = boardModel;
    this->color      = color;
}

ScoreBoardController::~ScoreBoardController(){}

void ScoreBoardController::updateLabel()
{
    this->scoreLabel->setString(String::createWithFormat("%d", this->boardModel->getNum(this->color))->getCString());
}