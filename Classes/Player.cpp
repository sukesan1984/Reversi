//
//  Player.cpp
//  Reversi
//
//  Created by Kosuke Takami on 2015/04/29.
//
//

#include "Player.h"

Player::Player(Color playerColor, BoardController* boardController)
{
    this->playerColor = playerColor;
    this->boardController = boardController;
}

Player::~Player(){}

void Player::setTurn(bool isMyTurn)
{
    this->isMyTurn = isMyTurn;
}

void Player::onCellClick(int x, int y)
{
    if(!this->isMyTurn)
        return;
    cocos2d::log("x:%d, y:%d, color:%d", x, y, this->playerColor);
    
}