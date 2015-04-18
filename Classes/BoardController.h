//
//  BoardController.h
//  Reversi
//
//  Created by Kosuke Takami on 2015/04/18.
//
//

#ifndef __Reversi__BoardController__
#define __Reversi__BoardController__

#include <stdio.h>
#include "cocos2d.h"

class BoardController
{
private:
    //boardのspriteへの参照
    cocos2d::Sprite* boardSprite;
    cocos2d::EventDispatcher* eventDispatcher;
    
    void Initialize();
    
public:
    BoardController();
    BoardController(cocos2d::Sprite* boardSprite, cocos2d::EventDispatcher* eventDispather);
    ~BoardController();
};

#endif /* defined(__Reversi__BoardController__) */
