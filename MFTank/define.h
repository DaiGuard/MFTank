/**
 * @file define.h
 * @brief プログラムの定義をまとめたヘッダファイル
 * @author DaiGuard
 * @date 2020/09/14
 */

#ifndef __DEFINE_H__
#define __DEFINE_H__


/**
 * @def DEGUB_SERIAL_BAUDRATE
 * @brief デバック用シリアル通信のボーレート
 */
#define DEGUB_SERIAL_BAUDRATE 115200

#define DEBUG_INFO(x) Serial.println("[Info]: " + x)
#define DEBUG_WARN(x) Serial.println("[Warn]: " + x)
#define DEBUG_ERR(x)  Serial.println("[Err ]: " + x)

/**
 * @def WEAPON_NUM
 * @brief 装備できる武器パーツの数
 */
#define WEAPON_NUM 3

// 武器パーツ1
/**
 * @def WEAPON1_ID_PWR_PIN
 * @brief 武器パーツ1のID OR PWR ピン番号
 */
#define WEAPON1_ID_PWR_PIN  A0
/**
 * @def WEAPON1_PWM1_PIN
 * @brief 武器パーツ1のPWM1出力 ピン番号
 */
#define WEAPON1_PWM1_PIN    2
/**
 * @def WEAPON1_PWM2_PIN
 * @brief 武器パーツ1のPWM2出力 ピン番号
 */
#define WEAPON1_PWM2_PIN    3

// 武器パーツ2
/**
 * @def WEAPON2_ID_PWR_PIN
 * @brief 武器パーツ2のID OR PWR ピン番号
 */
#define WEAPON2_ID_PWR_PIN  A1
/**
 * @def WEAPON2_PWM1_PIN
 * @brief 武器パーツ2のPWM1出力 ピン番号
 */
#define WEAPON2_PWM1_PIN    4
/**
 * @def WEAPON2_PWM2_PIN
 * @brief 武器パーツ2のPWM2出力 ピン番号
 */
#define WEAPON2_PWM2_PIN    5

// 武器パーツ3
/**
 * @def WEAPON3_ID_PWR_PIN
 * @brief 武器パーツ3のID OR PWR ピン番号
 */
#define WEAPON3_ID_PWR_PIN  A2
/**
 * @def WEAPON3_PWM1_PIN
 * @brief 武器パーツ3のPWM1出力 ピン番号
 */
#define WEAPON3_PWM1_PIN    6
/**
 * @def WEAPON3_PWM2_PIN
 * @brief 武器パーツ3のPWM2出力 ピン番号
 */
#define WEAPON3_PWM2_PIN    7


/**
 * @def RECV_PWM_NUM
 * @brief 受信するPWM信号の数
 */
#define RECV_PWM_NUM 5

#define RECV_PWM1_PIN 22
#define RECV_PWM2_PIN 23
#define RECV_PWM3_PIN 24
#define RECV_PWM4_PIN 25
#define RECV_PWM5_PIN 26

#define WEAPON_ID1_AD_MAX 619 // 3.024V / (5V / 1024)
#define WEAPON_ID1_AD_MIN 609 // 2.976V / (5V / 1024)

#define WEAPON_ID2_AD_MAX 517 // 2.525V / (5V / 1024)
#define WEAPON_ID2_AD_MIN 506 // 2.475V / (5V / 1024)

#define WEAPON_ID3_AD_MAX 331 // 1.620V / (5V / 1024)
#define WEAPON_ID3_AD_MIN 322 // 1.577V / (5V / 1024)

#define WEAPON_ID4_AD_MAX 187 // 0.917V / (5V / 1024)
#define WEAPON_ID4_AD_MIN 181 // 0.887V / (5V / 1024)

#endif
