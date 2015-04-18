//
//  BoardController.cpp
//  Reversi
//
//  Created by Kosuke Takami on 2015/04/18.
//
//

#include "BoardController.h"
#include "cocos2d.h"

BoardController::BoardController()
{
}

BoardController::BoardController(cocos2d::Sprite* boardSprite, cocos2d::EventDispatcher* eventDispatcher)
{
    this->boardSprite     = boardSprite;
    this->eventDispatcher = eventDispatcher;
    this->Initialize();
}

BoardController::~BoardController()
{
}

void BoardController::Initialize()
{
    // touch event
    // シングルタッチイベントリスナーを作成する。
    auto listener1 = cocos2d::EventListenerTouchOneByOne::create();
    // スワロータッチモードにするとonTouchBeganメソッドはタッチイベントは他では使われない。
    listener1->setSwallowTouches(true);
    
    // onTouchBeganイベントコールバック関数実装のラムダ式の例
    listener1->onTouchBegan = CC_CALLBACK_2(BoardController::OnTouchBegan, this);
    
    // タッチイベントが終了した場合
    listener1->onTouchEnded = CC_CALLBACK_2(BoardController::OnTouchEnded, this);

    this->eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, boardSprite);   this->boardSprite = boardSprite;
}

bool BoardController::OnTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
    // event->getCurrentTarget() は、リスナーのsceneGraphPriorityの優先順に対象オブジェクトを返す。
    auto target = static_cast<cocos2d::Sprite*>(event->getCurrentTarget());
    
    // ボタンに対する相対的な位置を取得する。
    cocos2d::Point locationInNode = target->convertToNodeSpace(touch->getLocation());
    // コンテンツのサイズを取得する。
    cocos2d::Size s = target->getContentSize();
    // コンテンツ矩形を作成する。
    cocos2d::Rect rect = cocos2d::Rect(0, 0, s.width, s.height);
    
    // クリックエリアをチェックする。
    if (rect.containsPoint(locationInNode))
    {
        cocos2d::log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
        // 不透明度を変更する。
        target->setOpacity(180);
        return true;
    }
    return false;
}

void BoardController::OnTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
    // ターゲットを取得する。
    auto target = static_cast<cocos2d::Sprite*>(event->getCurrentTarget());
    // ここに終了した場合の処理を書く。
    cocos2d::log("sprite onTouchesEnded.. ");
    // 不透明度を元に戻す。
    target->setOpacity(255);
}