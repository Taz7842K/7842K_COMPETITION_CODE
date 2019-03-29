#include "main.h"

#include "7842K_Main.h"

void setBasePower(int xPower, int yPower, int zPower)
{
  m_frontRight.move(yPower-xPower-zPower);
	m_rearRight.move(yPower+xPower-zPower);
	m_frontLeft.move(yPower+xPower+zPower);
  m_rearLeft.move(yPower-xPower+zPower);
}

void baseControlTask(void*)
{
  while(true)
  {
    double joystickch2 = HIDMain.get_analog(ANALOG_RIGHT_Y) * -1;
    double joystickch1 = HIDMain.get_analog(ANALOG_RIGHT_X) * -1;
    double joystickch4 = HIDMain.get_analog(ANALOG_LEFT_X);

    setBasePower(joystickch1,joystickch2,joystickch4);

    pros::delay(20);
  }
}
