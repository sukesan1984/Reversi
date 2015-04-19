//
//  BoardBuilder.h
//  Reversi
//
//  Created by Kosuke Takami on 2015/04/19.
//
//

#ifndef __Reversi__BoardBuilder__
#define __Reversi__BoardBuilder__

#include <stdio.h>
#include "cocos2d.h"
#include "BoardController.h"

///////////////////
/// Boardにまつわるいろいろを生成・管理するクラス
///////////////////
class BoardBuilder
{
private:
    BoardController *boardController;
    cocos2d::Layer *parentLayer;
    cocos2d::EventDispatcher* eventDispatcher;
public:
    BoardBuilder();
    BoardBuilder(cocos2d::Layer* parentLayer, cocos2d::EventDispatcher* eventDispatcher);
    ~BoardBuilder();
    
    ///中心座標を与えてその位置を中心に生成する。
    void create(cocos2d::Vec2 centerPos);
};
#endif /* defined(__Reversi__BoardBuilder__) */