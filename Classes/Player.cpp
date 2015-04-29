//
//  Player.cpp
//  Reversi
//
//  Created by Kosuke Takami on 2015/04/29.
//
//

#include "Player.h"

Player::Player(Color playerColor)
{
    this->playerColor = playerColor;
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
    
    std::vector<DelegateBase*>::iterator it;
    for(it = this->listeners.begin(); it != this->listeners.end(); ++it)
    {
        (**it)(x, y);
    }
}

void Player::setOnSelectHandler(DelegateBase *delegate)
{
    this->listeners.push_back(delegate);
}