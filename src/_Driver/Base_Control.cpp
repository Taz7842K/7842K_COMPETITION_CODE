#include "main.h"

#include "7842K_Main.h"

void baseControlTask()
{
  double joystickch2 = HIDMain.get_analog(ANALOG_RIGHT_Y) * -1;
  double joystickch4 = HIDMain.get_analog(ANALOG_LEFT_X) * 0.75;

  m_frontLeft.move(joystickch2 + joystickch4);
  m_rearLeft.move(joystickch2 + joystickch4);
  m_frontRight.move(joystickch2 - joystickch4);
  m_rearRight.move(joystickch2 - joystickch4);
}
