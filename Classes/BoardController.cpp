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

BoardController::BoardController(cocos2d::Sprite* boardSprite,
                                 PieceControllersHolder *pieceControllersHolder,
                                 MarkController **markControllers,
                                 BoardModel* boardModel,
                                 cocos2d::EventDispatcher* eventDispatcher,
                                 TurnController* turnController)
{
    this->boardSprite     = boardSprite;
    this->boardModel      = boardModel;
    this->pieceControllersHolder = pieceControllersHolder;
    this->markControllers = markControllers;
    this->eventDispatcher = eventDispatcher;
    this->turnController  = turnController;
    this->initialize();
}

BoardController::~BoardController()
{
}

void BoardController::initialize()
{
    // touch event
    // シングルタッチイベントリスナーを作成する。
    auto listener1 = cocos2d::EventListenerTouchOneByOne::create();
    // スワロータッチモードにするとonTouchBeganメソッドはタッチイベントは他では使われない。
    listener1->setSwallowTouches(true);
    
    // onTouchBeganイベントコールバック関数実装のラムダ式の例
    listener1->onTouchBegan = CC_CALLBACK_2(BoardController::onTouchBegan, this);
    
    // タッチイベントが終了した場合
    listener1->onTouchEnded = CC_CALLBACK_2(BoardController::onTouchEnded, this);

    this->eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this->boardSprite);
    
    // ボードの初期化
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            BoardModel::State currentState =this->boardModel->getState(i, j);
            this->pieceControllersHolder->get(i, j)->show(currentState);
        }
    }
}

bool BoardController::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
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
        
        Point touchPoint = this->getIndex(locationInNode);
        cocos2d::log("[index] x: %d, y:%d", touchPoint.x, touchPoint.y);
        PieceController *pieceController = this->pieceControllersHolder->get(touchPoint.x, touchPoint.y);
        this->boardModel->removeMarked();
        if(pieceController->isShown)
        {
            pieceController->changeColor();
            this->boardModel->changeColor(touchPoint.x, touchPoint.y);
        }
        else
        {
            switch(this->turnController->getCurrentTurn())
            {
                case TurnController::Turn::Black:
                    pieceController->show(PieceController::PieceColor::Black);
                    this->boardModel->setState(touchPoint.x, touchPoint.y, BoardModel::Black);
                    this->boardModel->setMarked(BoardModel::White);
                    break;
                case TurnController::Turn::White:
                    pieceController->show(PieceController::PieceColor::White);
                    this->boardModel->setState(touchPoint.x, touchPoint.y, BoardModel::White);
                    this->boardModel->setMarked(BoardModel::Black);
                    break;
                default:
                    break;
            }
            this->turnController->changeTurn();
            this->showMarkers();
            
        }
        
        return true;
    }
    return false;
}

void BoardController::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
}

Point BoardController::getIndex(cocos2d::Vec2 locationInNode)
{
    const int WidthNum = 8;
    const int HeightNum = 8;
    
    float width = this->boardSprite->getContentSize().width / (float) WidthNum;
    float height = this->boardSprite->getContentSize().height / (float) HeightNum;
    
    int indexX = (int) locationInNode.x / width;
    int indexY = (int) locationInNode.y / height;
    
    struct Point point;
    point.x = indexX;
    point.y = indexY;
    
    return point;
}

void BoardController::showMarkers()
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            BoardModel::State currentState =this->boardModel->getState(i, j);
            int index = 8 * j + i;
            if(currentState == BoardModel::State::Marked)
            {
                this->markControllers[index]->show();
            }
            else
            {
                this->markControllers[index]->hide();
            }
        }
    }
}