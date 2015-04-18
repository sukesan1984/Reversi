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

struct Point {
    int x;
    int y;
};
class BoardController
{
private:
    //boardのspriteへの参照
    cocos2d::Sprite* boardSprite;
    cocos2d::EventDispatcher* eventDispatcher;
    
    void initialize();
    
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    
    Point getIndex(cocos2d::Vec2 locationInNode);
public:
    BoardController();
    BoardController(cocos2d::Sprite* boardSprite, cocos2d::EventDispatcher* eventDispather);
    ~BoardController();
};

#endif /* defined(__Reversi__BoardController__) */
