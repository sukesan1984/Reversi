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
#include "PieceControllersHolder.h"
#include "BoardModel.h"
#include "MarkController.h"
#include "DelegateBase.h"

#include <vector>

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
    PieceControllersHolder *pieceControllersHolder;
    MarkController **markControllers;
    BoardModel* boardModel;
    //TurnController* turnController;
    std::vector<DelegateBase*> listeners;
    
    void initialize();
    
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
    
    Point getIndex(cocos2d::Vec2 locationInNode);
    void showMarkers();
    void startReverse();
public:
    BoardController();
    BoardController(cocos2d::Sprite* boardSprite,
                    PieceControllersHolder* pieceControllersHolder,
                    MarkController **markControllers,
                    BoardModel* boardModel,
                    cocos2d::EventDispatcher* eventDispather);
                    //TurnController* turnController);
    ~BoardController();
    void setOnClickHandler(DelegateBase* delegate);
};

#endif /* defined(__Reversi__BoardController__) */
