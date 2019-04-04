#include "main.h"
#include "7842K_Main.h"

catapultStates catapultState = catapultStates::loaded;

void catapultControlTask(void*)
{
  m_catapult.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);

  while(true)
  {
//     //---------------------------------manual catapult control--------------------------------------------------
//     if(pot_catapult.get()<2200)
//     {
//       m_catapult.move(-127);
//     }
//     else if(HIDMain.get_digital(DIGITAL_R2))
// {
//       m_catapult.move(-127);
//
// }
//     else
//     {
//       m_catapult.move(0);
//     }
//     //---------------------------------manual catapult control--------------------------------------------------


    switch (catapultState)
    {
      case catapultStates::loading:

      m_catapult.move(-127);

      if (pot_catapult.get() > 2200)
      {
        m_catapult.move(0);
        catapultState = catapultStates::loaded;
      }
      break;

      case catapultStates::loaded:

      if(HIDMain.get_digital(DIGITAL_R2))
      {
        m_catapult.move(-127);
      }

      else if(pot_catapult.get() < 1500)
      {
        catapultState = catapultStates::loading;
      }

      else
      {
        m_catapult.move(0);
      }

      break;

      case catapultStates::trigger:

      m_catapult.move(-127);

      if(pot_catapult.get() < 1500)
      {
        pros::delay(150);

        catapultState = catapultStates::loading;
      }

    }
    pros::delay(20);
  }
}
