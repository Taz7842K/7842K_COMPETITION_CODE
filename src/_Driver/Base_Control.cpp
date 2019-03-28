#include "main.h"

#include "7842K_Main.h"

void setBasePower(int xPower, int yPower, int zPower)
{
  m_frontRight.move(yPower-xPower-zPower);
	m_rearRight.move(yPower+xPower-zPower);
	m_frontLeft.move(yPower+xPower+zPower);
  m_rearLeft.move(yPower-xPower+zPower);
}

void baseControlTask()
{

    double joystickch2 = HIDMain.get_analog(ANALOG_RIGHT_Y) * -1;
    double joystickch1 = HIDMain.get_analog(ANALOG_RIGHT_X);
    double joystickch4 = HIDMain.get_analog(ANALOG_LEFT_X);

    setBasePower(joystickch1,joystickch2,joystickch4);
}
