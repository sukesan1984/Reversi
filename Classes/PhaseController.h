//
//  PhaseController.h
//  Reversi
//
//  Created by Kosuke Takami on 2015/04/19.
//
//

#ifndef __Reversi__PhaseController__
#define __Reversi__PhaseController__

#include <stdio.h>

/////////////////////////////////
// ターンの各フェーズを制御するやつ
// 1. 置けるマスチェック
// 2. 置けるマスに色つける
// 3. 置く
// 4. ひっくりがえす（カウントして、スコアに反映）
// 5. ターン終了
/////////////////////////////////
class PhaseController
{
    PhaseController();
    ~PhaseController();
};

#endif /* defined(__Reversi__PhaseController__) */
