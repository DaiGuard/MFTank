/**
 * @file PWMReceiver.h
 * @brief PWM信号を受信するクラス
 * @author DaiGuard
 * @date 2020/09/14
 */

#ifndef __PWM_RECEIVER_H__
#define __PWM_RECEIVER_H__

#include <Arduino.h>

/**
 * @class PWMReceiver
 * @brief PWM信号を受信するクラス
 */
class PWMReceiver
{
  public:
    /**
     * @enum PWMReceiverStatus
     * 武器パーツの状態リスト
     */
    enum PWMReceiverStatus{
      // コントローラと接続できていない
      DISCONNECTED,
      // コントローラと接続できている
      CONNECTED
    };

    /**
     * @fn PWMReceiver
     * @brief PWM信号を受信するクラスのコンストラクタ
     * @param (pin_PWM) 受信するPWM信号のピン番号
     */
    PWMReceiver(uint8_t pin_PWM);
    /**
     * @fn ~PWMReceiver
     * @brief PWM信号を受信するクラスのデストラクタ
     */
    ~PWMReceiver();

    /**
     * @fn getDutyRatio
     * @brief 受信したPWMのON時間
     * @return ON時間[ms], 未接続時は0を返す
     */
    unsigned long getDutyRatio();

    /**
     * @fn getState
     * @brief 現在のPWM受信ステータスを取得
     * @return 現在のステータス
     */
    PWMReceiverStatus getStatus(){ return _status; }

    /**
     * @fn assignPinRole     
     * @brief 割り振られたピンの動作モードを設定する
     */
    void assignPinRole();
    
  private:
    // 武器パーツの現在状態
    PWMReceiverStatus _status;

    // PWM信号を受信するピン番号
    uint8_t _pin_PWM;
};

#endif
