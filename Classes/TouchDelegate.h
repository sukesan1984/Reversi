//
//  Delegate.h
//  Reversi
//
//  Created by Kosuke Takami on 2015/04/29.
//
//

#ifndef __Reversi__Delegate__
#define __Reversi__Delegate__

#include <stdio.h>
#include "DelegateBase.h"
#include "Player.h"

template <class T>
class TouchDelegate : public DelegateBase {
public:
    TouchDelegate(){};
    virtual ~TouchDelegate(){};
    
    virtual void operator()(int value1, int value2){
        (m_obj->*m_func)(value1, value2); // ハンドラ実行
    }
    
    typedef void (T::*EventFunc)(int, int);
    
    void set(T* obj, EventFunc func){
        m_obj = obj;
        m_func = func;
    };
    
    static DelegateBase* createDelegator(T* obj, void(T::*func)(int, int)){
        TouchDelegate* dg = new TouchDelegate;
        dg->set(obj, func);
        return dg;
    }
    
protected:
    T* m_obj;
    EventFunc m_func;
};

#endif /* defined(__Reversi__Delegate__) */
