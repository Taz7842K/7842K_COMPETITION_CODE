#include "main.h"
#include "7842K_Main.h"

void liftControlTask(void*)
{
  m_lift1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  m_lift2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  double wantedPower = 0;
  double actualPower = 0;
  double powerError = 0;

  while (true)
  {
    if(HIDMain.get_digital(DIGITAL_L2))                   //Moves lift down
    {
      wantedPower = 70;
    }
    else if(HIDMain.get_digital(DIGITAL_L1))              //Moves lift up
    {
      wantedPower = -70;
    }
    else
    {
      wantedPower = 0;
    }

    slewRatePos();
    slewRateNeg();
  }
}
