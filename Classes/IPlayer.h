//
//  IPlayer.h
//  Reversi
//
//  Created by Kosuke Takami on 2015/05/03.
//
//

#ifndef Reversi_IPlayer_h
#define Reversi_IPlayer_h

#include "Const.h"//;
#include "DelegateBase.h"//;

///Playerクラスのinterface

class IPlayer
{
public:
    virtual ~IPlayer(){};
    virtual void setOnSelectHandler(DelegateBase* delegate) = 0;
};

#endif
