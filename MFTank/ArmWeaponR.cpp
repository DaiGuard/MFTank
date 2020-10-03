#include "ArmWeaponR.h"


void armWeaponRMotion(WeaponInformation* weapon, uint16_t pwm)
{
  digitalWrite(weapon->_pin_ID_PWR, HIGH);

  if(pwm > 2000)
  {
    weapon->_servo_1.write(180);
    weapon->_servo_2.write(180);
  }
  else if(pwm < 1600)
  {
    weapon->_servo_1.write(113);
    weapon->_servo_2.write(85);
  }
  else
  {
    weapon->_servo_1.write(113);
    weapon->_servo_2.write(140);
  }
}