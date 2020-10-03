/**
 * @file PWMReceiver.cpp
 * @brief PWM信号を受信するクラス
 * @author DaiGuard
 * @date 2020/09/14
 */

#include "PWMReceiver.h"
#include "define.h"


PWMReceiver::PWMReceiver(uint8_t pin_PWM)
{
  /**
   * PWM受信クラスの状態を初期化
   */
  _status = PWMReceiverStatus::DISCONNECTED;

  /**
   * ピン番号を初期登録する
   */
  _pin_PWM = pin_PWM;
}


PWMReceiver::~PWMReceiver()
{
  /**
   * None
   */
}


void PWMReceiver::assignPinRole()
{  
  /**
   * ※動作に影響しなかったので廃止
   */
  pinMode(_pin_PWM, INPUT);
}

unsigned long PWMReceiver::getDutyRatio()
{
  static unsigned long high_time = 0u;    

  high_time = pulseIn(_pin_PWM, HIGH, 40000);  

  if(high_time > 0u)
    _status = PWMReceiverStatus::CONNECTED;
  else
    _status = PWMReceiverStatus::DISCONNECTED;

  return high_time;
}