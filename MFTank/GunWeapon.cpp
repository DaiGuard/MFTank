#include "GunWeapon.h"


void gunWeaponMotion(WeaponInformation* weapon, uint16_t pwm)
{
  // 銃を切る
  if(pwm < 1600)
  {
    digitalWrite(weapon->_pin_ID_PWR, LOW);
    digitalWrite(weapon->_pin_PWM1, LOW);
    digitalWrite(weapon->_pin_PWM2, LOW);
  }
  else
  {
    digitalWrite(weapon->_pin_ID_PWR, HIGH);
    digitalWrite(weapon->_pin_PWM1, HIGH);
    digitalWrite(weapon->_pin_PWM2, HIGH);
  }
}