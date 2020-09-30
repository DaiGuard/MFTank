/**
 * @file WeaponInformation.h
 * @brief 武器パーツの情報を格納するクラス
 * @author DaiGuard
 * @date 2020/09/14
 */

#ifndef __WEAPON_INFORMATION_H__
#define __WEAPON_INFORMATION_H__

#include <Arduino.h>

/**
 * @class WeaponInformation
 * @brief 武器パーツ情報を格納するクラス
 */
class WeaponInformation
{
  public:
    /**
     * @enum WeaponStatus
     * 武器パーツの状態リスト
     */
    enum WeaponStatus{
      // ID確定前
      ID_UNKNOWN,
      // ID確定後
      ID_ASSIGN,
    };

    /**
     * @fn WeaponInformation
     * @brief 武器パーツの情報を格納するクラスのコンストラクタ
     * @param (pin_ID_PWR) ID or PWRを管理するピン番号
     * @param (pin_PWM1) PWM1を出力するピン番号
     * @param (pin_PWM2) PWM2を出力するピン番号
     */
    WeaponInformation(uint8_t pin_ID_PWR, uint8_t pin_PWM1, uint8_t pin_PWM2);
    /**
     * @fn ~WeaponInformation
     * @brief 武器パーツ情報を格納するクラスのデストラクタ
     */
    ~WeaponInformation();

    /**
     * @fn readWeaponID
     * @brief 武器IDを読み取る
     * @return 読み取った武器IDを返す
     */
    uint8_t readWeaponID();

    /**
     * @fn getStatus
     * @brief 現在の武器パーツの状態を取得する
     */
    WeaponStatus getStatus(){ return _status; }

  private:
    // 武器パーツの現在状態
    WeaponStatus _status;

    // 武器パーツのID or PWR ピン番号
    uint8_t _pin_ID_PWR;
    // 武器パーツのPWM1 ピン番号
    uint8_t _pin_PWM1;
    // 武器パーツのPWM2 ピン番号
    uint8_t _pin_PWM2;
    // 武器パーツのID番号
    uint8_t _weapon_ID;

    /**
     * @fn assignPinRole     
     * @brief 武器パーツに割り振られたピンの動作モードを設定する
     * @param (id_or_pwr) false: ID読み取りモード, true: PWRモード
     */
    void assignPinRole(bool id_or_pwr);

    /**
     * @fn motionFunc     
     * @brief 武器の動作を記述する仮想関数
     */
    virtual void motionFunc();
};


#endif
