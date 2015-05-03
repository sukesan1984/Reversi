//
//  TitleScene.h
//  Reversi
//
//  Created by Kosuke Takami on 2015/05/03.
//
//

#ifndef __Reversi__TitleScene__
#define __Reversi__TitleScene__

#include <stdio.h>
#include "cocos2d.h"

class TitleScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(TitleScene);
};

#endif /* defined(__Reversi__TitleScene__) */
