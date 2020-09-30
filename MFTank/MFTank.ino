/**
 * @file MFTank.ino
 * @brief MFT2020用タンクの動作プログラム
 * @author DaiGuard
 * @date 2020/09/14
 */

#include "define.h"
#include "StateTransition.h"
#include "WeaponInformation.h"
#include "PWMReceiver.h"
#include "DamegeControl.h"


// ロボットの状態
StateTransition robotState;

// 武器のモーション定義
WeaponInformation weapons[WEAPON_NUM] = {
  WeaponInformation(WEAPON1_ID_PWR_PIN, WEAPON1_PWM1_PIN, WEAPON1_PWM2_PIN),
  WeaponInformation(WEAPON2_ID_PWR_PIN, WEAPON2_PWM1_PIN, WEAPON2_PWM2_PIN),
  WeaponInformation(WEAPON3_ID_PWR_PIN, WEAPON3_PWM1_PIN, WEAPON3_PWM2_PIN)
};

// PWM信号受信
PWMReceiver recvPwms[RECV_PWM_NUM] = {
  PWMReceiver(RECV_PWM1_PIN),
  PWMReceiver(RECV_PWM2_PIN),
  PWMReceiver(RECV_PWM3_PIN),
  PWMReceiver(RECV_PWM4_PIN),
  PWMReceiver(RECV_PWM5_PIN),  
};


/**
 * @fn setup
 * @brief Arduino標準の初期化関数
 */
void setup() {
  // 起動時一回実行する。セットアップ関数  

  /**
   * デバック用シリアルポートの初期化
   */
  Serial.begin(DEGUB_SERIAL_BAUDRATE);

  /**
   * ダメージ用割り込み関数の設定
   */
  DamegeControl::setInterrupt(NULL, NULL, NULL);
}

/**
 * @fn loop
 * @brief Arduino標準の繰り返し関数
 */
void loop() {
  /**
   * 使用する変数を宣言する
   */
  static unsigned long s_time = 0u;
  static unsigned long e_time = 0u;
  // 発生したイベントリスト
  uint32_t events = 0u;  
  // 受信したPWMデューティ比
  static uint16_t ratios[RECV_PWM_NUM];    

  /**
   * 実行後からの経過時間を出力する
   */  
  e_time = millis();
  Serial.print(e_time - s_time); Serial.print(" [ms]: ");
  s_time = e_time;  

  /**
   * PWM信号を受信する
   */
  bool connected = true;
  for(int i = 0; i < RECV_PWM_NUM; i++)
  {
    ratios[i] = recvPwms[i].getDutyRatio();

    // 無線受信切れを確認する
    if(recvPwms[i].getStatus() == PWMReceiver::DISCONNECTED)
      connected = false;
  }

  // 無線受信状態のイベントを整理する
  if(connected)
  {
    events |= StateTransition::COMMNICATION_GAIN;
  }
  else
  {
    events |= StateTransition::COMMUNICATION_LOSS;
  }
  
  /**
   * HP確認
   */
  if(DamegeControl::getHP() <= 0)
  {
    events |= StateTransition::HP_ZERO;
  }
  else{
    events |= StateTransition::HP_RECOVER;
  }

  /**
   * 
   */
  switch(robotState.getState())
  {
  case StateTransition::INITIALIZING:
    /**
     * 武器IDチェックを行う
     */
    for(int i=0; i<WEAPON_NUM; i++)
    {
      int id = weapons[i].readWeaponID();
      Serial.print(id);
      Serial.print(", ");
    }
    Serial.print(":WEAPN, ");

    events |= StateTransition::INIT_COMP;

  break;
  case StateTransition::ROBOT_ACTIVE:
    /**
     * 各武器に動作指示を行う
     */
  break;
  case StateTransition::ROBOT_PASSIVE:
    /**
     * 何もしない
     */
  break;
  }

  /**
   * ロボットの状態を更新する
   */  
  robotState.updateState(events);
  Serial.print(robotState.getState());
  Serial.print(":STATE, ");

  /**
   * デバック用シリアルの改行
   */
  Serial.println("");
}
