/**
 * @file WeaponInformation.cpp
 * @brief 武器パーツの情報を格納するクラス
 * @author DaiGuard
 * @date 2020/09/14
 */

#include "WeaponInformation.h"
#include "define.h"


WeaponInformation::WeaponInformation(
  uint8_t pin_ID_PWR, uint8_t pin_PWM1, uint8_t pin_PWM2)
{
  /**
   * 武器パーツの状態を初期化
   */
  _status = WeaponStatus::ID_UNKNOWN;
  
  /**
   * ピン番号を初期登録する
   */
  _pin_ID_PWR = pin_ID_PWR;
  _pin_PWM1 = pin_PWM1;
  _pin_PWM2 = pin_PWM2;

  /**
   * 武器IDを初期化する
   */
  _weapon_ID = 0;
}


WeaponInformation::~WeaponInformation()
{
  /**
   * None
   */ 
}


void WeaponInformation::assignPinRole(bool id_or_pwr, bool enable_servo)
{
  if(id_or_pwr)
  {  
    pinMode(_pin_ID_PWR, OUTPUT);
  }
  else{
    pinMode(_pin_ID_PWR, INPUT);
  }

  pinMode(_pin_PWM1, OUTPUT);
  pinMode(_pin_PWM2, OUTPUT);

  if(enable_servo)
  {
    _servo_1.attach(_pin_PWM1, 500, 2400);
    _servo_2.attach(_pin_PWM2, 500, 2400);
  }
}


uint8_t WeaponInformation::readWeaponID()
{
  int value = 0;

  if(_status == WeaponStatus::ID_UNKNOWN)
  {
    /**
     * ID読み取りモードへ切り替え
     */
    // assignPinRole(false);
    delay(100);

    /**
     * アナログ値から武器IDを更新する
     */
    value = analogRead(_pin_ID_PWR);

    if(WEAPON_ID1_AD_MIN < value && value < WEAPON_ID1_AD_MAX)
    {
      _weapon_ID = 1;
    }
    else if(WEAPON_ID2_AD_MIN < value && value < WEAPON_ID2_AD_MAX)
    {
      _weapon_ID = 2;
    }
    else if(WEAPON_ID3_AD_MIN < value && value < WEAPON_ID3_AD_MAX)
    {
      _weapon_ID = 3;
    }
    else if(WEAPON_ID4_AD_MIN < value && value < WEAPON_ID4_AD_MAX)
    {
      _weapon_ID = 4;
    }

    /**
     * 動作指示モードへ切り替え
     */
    // assignPinRole(true);
    delay(100);
  }

  return _weapon_ID;
}


void WeaponInformation::stopEnergy()
{
  digitalWrite(_pin_ID_PWR, LOW);
}