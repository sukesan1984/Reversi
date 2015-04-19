//
//  MarkController.h
//  Reversi
//
//  Created by Kosuke Takami on 2015/04/19.
//
//

#ifndef __Reversi__MarkController__
#define __Reversi__MarkController__

#include <stdio.h>
#include "cocos2d.h"
class MarkController
{
private:
    cocos2d::Vec2 currentPosition;
    cocos2d::Sprite *markSprite;
public:
    MarkController(cocos2d::Sprite *markSprite, cocos2d::Vec2 defaultPosition);
    MarkController();
    ~MarkController();
    void show();
    void hide();
};
#endif /* defined(__Reversi__MarkController__) */
