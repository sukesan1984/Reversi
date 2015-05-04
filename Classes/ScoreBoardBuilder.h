//
//  ScoreBoardBuilder.h
//  Reversi
//
//  Created by Kosuke Takami on 2015/05/04.
//
//

#ifndef __Reversi__ScoreBoardBuilder__
#define __Reversi__ScoreBoardBuilder__

#include <stdio.h>
#include "BoardModel.h"

class ScoreBoardBuilder
{
private:
    BoardModel* boardModel;
    
public:
    ScoreBoardBuilder();
    ~ScoreBoardBuilder();
};

#endif /* defined(__Reversi__ScoreBoardBuilder__) */
