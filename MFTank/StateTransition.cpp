/**
 * @file StateTransition.cpp
 * @brief ロボットの状態遷移を管理するクラス
 * @author DaiGuard
 * @date 2020/09/14
 */

#include "StateTransition.h"
#include "define.h"


StateTransition::StateTransition()
{
  _state = RobotState::INITIALIZING;
}


StateTransition::~StateTransition()
{

}


StateTransition::RobotState StateTransition::updateState(int event)
{
  /*
   * 状態遷移の分岐を記述
   */
  switch (_state)
  {
  // 状態：初期化処理中
  case RobotState::INITIALIZING: 
    // イベント：初期化完了
    if(eventCheck(event, RobotEvent::INIT_COMP))
    {
      _state = RobotState::COMMUNICATION_CHECKING;
    }
    break;
  case RobotState::COMMUNICATION_CHECKING:
    // イベント：無線通信確立
    if(eventCheck(event, RobotEvent::COMMNICATION_GAIN))
    {
      _state = RobotState::ROBOT_ACTIVE;
    }
    break;
  case RobotState::ROBOT_ACTIVE:
    // イベント：無線通信切れ
    if(eventCheck(event, RobotEvent::COMMUNICATION_LOSS))
    {
      _state = RobotState::COMMUNICATION_CHECKING;
    }
    // イベント：HP切れ
    else if(eventCheck(event, RobotEvent::HP_ZERO))
    {
      _state = RobotState::ROBOT_PASSIVE;
    }
    break;
  case RobotState::ROBOT_PASSIVE:
    // イベント：無線通信切れ
    if(eventCheck(event, RobotEvent::COMMUNICATION_LOSS))
    {
      _state = RobotState::COMMUNICATION_CHECKING;
    }
    // イベント：HP回復
    else if(eventCheck(event, RobotEvent::HP_RECOVER))
    {
      _state = RobotState::ROBOT_ACTIVE;
    }
    break;
  default:
    break;
  }
}


bool StateTransition::eventCheck(int event, RobotEvent target)
{
  if((event & target) > 0)
  {
    return true;
  }
  else
  {
    return false;  
  }
}