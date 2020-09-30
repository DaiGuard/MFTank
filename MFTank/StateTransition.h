/**
 * @file StateTransition.h
 * @brief ロボットの状態遷移を管理するクラス
 * @author DaiGuard
 * @date 2020/09/14
 */

#ifndef __STATE_TRANSITION_H__
#define __STATE_TRANSITION_H__

#include <Arduino.h>

/**
 * @class StateTransition
 * @brief ロボットの状態遷移を管理するクラス
 */
class StateTransition
{

  public:
    /**
     * @enum RobotState
     * ロボットの状態
     */
    enum RobotState{
      // 初期化中
      INITIALIZING = 0,
      // 通信確認中
      COMMUNICATION_CHECKING = 1,
      // ロボット動作中
      ROBOT_ACTIVE = 2,
      // ロボット停止中
      ROBOT_PASSIVE = 3,
    };

    /**
     * @enum RobotEvent
     * ロボットで発生するイベント
     */
    enum RobotEvent{
      // 初期化完了
      INIT_COMP = 0x01,
      // 通信切れ
      COMMUNICATION_LOSS = 0x02,
      // 通信確立
      COMMNICATION_GAIN = 0x04,
      // HP回復
      HP_RECOVER = 0x08,
      // HP切れ
      HP_ZERO = 0x10,
    };

    /**
     * @fn StateTransition
     * @brief ロボットの状態遷移を管理するクラスのコンストラクタ     
     */
    StateTransition();
    /**
     * @fn ~StateTransition
     * @brief ロボットの状態遷移を管理するクラスのデストラクタ
     */
    ~StateTransition();

    /**
     * @fn updateState
     * @brief ロボットの状態を新しい状態に遷移させる
     * @param (event) 1回のループ中に発生したイベントリスト
     * @return 新しい状態
     */
    RobotState updateState(int event);

    /**
     * @fn getState
     * @brief 現在の状態を返す
     * @return 現在の状態
     */
    RobotState getState(){ return _state; }

  private:
    RobotState _state;

    /**
     * @fn eventCheck
     * @brief イベントリストから特定のイベントが発生したか判断する
     * @param (event) 発生したイベントリスト
     * @param (target) 発生したか確認したイベント識別子
     * @return 発生していた: true, 発生していない: false
     */
    bool eventCheck(int event, RobotEvent target);
};


#endif