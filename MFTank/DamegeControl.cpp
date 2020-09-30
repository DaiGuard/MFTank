/**
 * @file DamegeControl.cpp
 * @brief HP情報を格納するクラス
 * @author DaiGuard
 * @date 2020/09/14
 */


#include "DamegeControl.h"


int DamegeControl::_robot_hp = 10;

void DamegeControl::setInterrupt(int* level1_pins, int* level2_pins, int* level3_pins)
{
  /**
   * HPを初期値にする
   */  

  if(level1_pins != NULL){
    for(int i=0; i<sizeof(level1_pins) / sizeof(int); i++)
    {
      attachInterrupt(level1_pins[i], DamegeControl::damegeHitLevel1, RISING);
    }
  }

  if(level2_pins != NULL){
    for(int i=0; i<sizeof(level2_pins) / sizeof(int); i++)
    {
      attachInterrupt(level2_pins[i], DamegeControl::damegeHitLevel2, RISING);
    }
  }

  if(level3_pins != NULL){
    for(int i=0; i<sizeof(level3_pins) / sizeof(int); i++)
    {
      attachInterrupt(level3_pins[i], DamegeControl::damegeHitLevel3, RISING);
    }
  }

}


void DamegeControl::damegeHitLevel1()
{
  if(DamegeControl::_robot_hp > 0)
  {
    DamegeControl::_robot_hp = DamegeControl::_robot_hp - 1;
  }
  else
  {
    DamegeControl::_robot_hp = 10;
  }
  
  if(DamegeControl::_robot_hp < 0)
  {
    DamegeControl::_robot_hp = 0;
  }
}

void DamegeControl::damegeHitLevel2()
{
  if(DamegeControl::_robot_hp > 0)
  {
    DamegeControl::_robot_hp = DamegeControl::_robot_hp - 2;
  }
  else
  {
    DamegeControl::_robot_hp = 10;
  }
  
  if(DamegeControl::_robot_hp < 0)
  {
    DamegeControl::_robot_hp = 0;
  }
}

void DamegeControl::damegeHitLevel3()
{
  if(DamegeControl::_robot_hp > 0)
  {
    DamegeControl::_robot_hp = DamegeControl::_robot_hp - 3;
  }
  else
  {
    DamegeControl::_robot_hp = 10;
  }
  
  if(DamegeControl::_robot_hp < 0)
  {
    DamegeControl::_robot_hp = 0;
  }
}

int DamegeControl::getHP()
{
  return DamegeControl::_robot_hp;
}