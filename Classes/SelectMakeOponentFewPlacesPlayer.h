//
//  SelectMakeOponentFewPlacesPlayer.h
//  Reversi
//
//  Created by Kosuke Takami on 2015/05/04.
//
//

#ifndef __Reversi__SelectMakeOponentFewPlacesPlayer__
#define __Reversi__SelectMakeOponentFewPlacesPlayer__

#include <stdio.h>
#include "NPCBase.h"
class SelectMakeOponentFewPlacesPlayer : public NPCBase
{
public:
    SelectMakeOponentFewPlacesPlayer(Color playerColor, BoardModel* boardModel);
    void setTurn(bool isMyTurn);
};

#endif /* defined(__Reversi__SelectMakeOponentFewPlacesPlayer__) */

