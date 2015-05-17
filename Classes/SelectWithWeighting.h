//
//  SelectWithWeighting.h
//  Reversi
//
//  Created by Kosuke Takami on 2015/05/17.
//
//

#ifndef __Reversi__SelectWithWeighting__
#define __Reversi__SelectWithWeighting__

#include <stdio.h>
#include "NPCBase.h"

class SelectWithWeighting : public NPCBase
{
private:
    int *weighting;
public:
    explicit SelectWithWeighting(Color playerColor, BoardModel* boardModel);
    void setTurn(bool isMyTurn);
};
#endif /* defined(__Reversi__SelectWithWeighting__) */
