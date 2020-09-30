/**
 * @file DamegeControl.h
 * @brief HP情報を格納するクラス
 * @author DaiGuard
 * @date 2020/09/14
 */

#ifndef __DAMEGE_CONTROL_H__
#define __DAMEGE_CONTROL_H__


#include <Arduino.h>


/**
 * @class DamegeControl
 * @brief ロボットのHPを格納する
 */
class DamegeControl
{
  public:
    /**
     * @fn setInterrupt
     * @brief 割り込み関数の設定
     * @param (level1_pins) ダメージレベル1の割り込みを発生させるピンのリスト
     * @param (level2_pins) ダメージレベル1の割り込みを発生させるピンのリスト
     * @param (level3_pins) ダメージレベル1の割り込みを発生させるピンのリスト
     */
    static void setInterrupt(int* level1_pins, int* level2_pins, int* level3_pins);

    static void damegeHitLevel1();
    static void damegeHitLevel2();
    static void damegeHitLevel3();    

    static int getHP();

  private:
    static int _robot_hp;
};

#endif
