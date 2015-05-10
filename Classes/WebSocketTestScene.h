//
//  WebSocketTestScene.h
//  Reversi
//
//  Created by Kosuke Takami on 2015/05/09.
//
//

#ifndef __Reversi__WebSocketTestScene__
#define __Reversi__WebSocketTestScene__

#include <stdio.h>
#include "cocos2d.h"
#include <SocketIO.H>
#include "SocketIOWrapper.h"
#include "ui/cocosGUI.h"

using namespace cocos2d::network;
using namespace cocos2d::ui;

class WebSocketTestScene : public cocos2d::Layer, public SocketIO::SIODelegate
{
private:
    int index;
    SocketIOWrapper* _client;
    TextField* editBox;
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // socket.io eventのevent listener
    void onReceiveEvent(SIOClient* client , const std::string& data);
    
    // SIODelegate
    virtual void onConnect(SIOClient* client);
    virtual void onMessage(SIOClient* client, const std::string& data);
    virtual void onClose(SIOClient* client);
    virtual void onError(SIOClient* client, const std::string& data);
    
    // UI周り
    void textFieldEvent(Ref *pSender, TextField::EventType type);
    void addTalkPlayer(const std::string& str);
    void addTalkOther(const std::string& str);
    
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(WebSocketTestScene);
};

#endif /* defined(__Reversi__WebSocketTestScene__) */
