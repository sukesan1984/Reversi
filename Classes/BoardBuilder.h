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
#include "BoardModel.h"
#include "PieceController.h"
#include "PieceControllersHolder.h"
#include "MarkController.h"

///////////////////
/// Boardにまつわるいろいろを生成・管理するクラス
///////////////////
class BoardBuilder
{
private:
    BoardController *boardController;
    cocos2d::Layer *parentLayer;
    cocos2d::EventDispatcher* eventDispatcher;
    PieceController** createPieceControllers(cocos2d::Vec2 centerPos);
    PieceController** pieceControllers;
    PieceControllersHolder* pieceControllersHolder;
    cocos2d::Sprite *boardSprite;
    cocos2d::Sprite** pieceSprites;
    cocos2d::Sprite** markSprites;
    BoardModel * boardModel;
    //TurnController* turnController;
    MarkController** markControllers;
public:
    BoardBuilder();
    BoardBuilder(cocos2d::Layer* parentLayer, cocos2d::EventDispatcher* eventDispatcher);
    ~BoardBuilder();
    
    ///中心座標を与えてその位置を中心に生成する。
    BoardController* create(cocos2d::Vec2 centerPos, BoardModel* boardModel);
};
#endif /* defined(__Reversi__BoardBuilder__) */
