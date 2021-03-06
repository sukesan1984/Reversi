#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "BoardBuilder.h"
#include "BoardController.h"
#include "TurnController.h"
#include "IPlayer.h"
#include "Player.h"
#include "SelectRandomPlayer.h"
#include "SelectMakeOponentFewPlacesPlayer.h"
#include "SelectWithWeighting.h"
#include "Const.h"
#include "TouchDelegate.h"
#include "ScoreBoardController.h"

class GameMain : public cocos2d::Layer
{
private:
    BoardController* boardController;
    BoardModel* boardModel;
    BoardBuilder* boardBuilder;
    TurnController* turnController;
    void update(float frame);
    ScoreBoardController* scoreBoardControllerBlack;
    ScoreBoardController* scoreBoardControllerWhite;
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    void onClickHomeButton(cocos2d::Ref* pSender);
    void onClickSettingButton(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameMain);
};

#endif // __HELLOWORLD_SCENE_H__
