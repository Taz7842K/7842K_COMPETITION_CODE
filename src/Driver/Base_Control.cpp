#include "main.h"

#include "7842K_Main.h"

void baseControlTask()
{
  long joystickch2 = HIDMain.get_analog(ANALOG_RIGHT_Y) /127;
  long joystickch4 = HIDMain.get_analog(ANALOG_LEFT_X) /127 * 0.75;

  skidBase.arcade(joystickch2,joystickch4);
}
