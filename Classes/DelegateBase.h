//
//  DelegateBase.h
//  Reversi
//
//  Created by Kosuke Takami on 2015/04/29.
//
//

#ifndef Reversi_DelegateBase_h
#define Reversi_DelegateBase_h

class DelegateBase {
public:
    DelegateBase(){};
    virtual ~DelegateBase(){};
    
    virtual void operator()(int value1, int value2) = 0;
};

#endif
