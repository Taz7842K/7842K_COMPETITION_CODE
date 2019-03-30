#include "main.h"
#include "7842K_Main.h"

void catapultControlTask(void*)
{
  m_catapult.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);

  while(true)
  {

    switch (catapultState)
    {
      case catapultStates::loading:

      m_catapult.move(-127);

      if (light_catapult.get_value_calibrated() > 160)
      {
        m_catapult.move(0);
        catapultState = catapultStates::loaded;
      }
      break;

      case catapultStates::loaded:

      if(HIDMain.get_digital(DIGITAL_R2))                             //shoots catapult and provides manual control
      {
        m_catapult.move(-127);
      }

      else if(light_catapult.get_value_calibrated() < 70)
      {
        catapultState = catapultStates::loading;
      }

      else
      {
        m_catapult.move(0);
      }

      break;
    }
    pros::delay(20);
  }
}
