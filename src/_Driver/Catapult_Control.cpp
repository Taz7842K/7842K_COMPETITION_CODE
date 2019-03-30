#include "main.h"
#include "7842K_Main.h"

catapultStates catapultState = catapultStates::loaded;

void catapultControlTask(void*)
{
  m_catapult.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);

  while(true)
  {
    //---------------------------------manual catapult control--------------------------------------------------
    if(pot_catapult.get()<2200)
    {
      m_catapult.move(-127);
    }
    else if(HIDMain.get_digital(DIGITAL_R2))
{
      m_catapult.move(-127);

}
    else
    {
      m_catapult.move(0);
    }
    //---------------------------------manual catapult control--------------------------------------------------


    // switch (catapultState)
    // {
    //   case catapultStates::loading:
    //
    //   m_catapult.move(-127);
    //
    //   if (light_catapult.get_value_calibrated() > 160)
    //   {
    //     m_catapult.move(0);
    //     catapultState = catapultStates::loaded;
    //   }
    //   break;
    //
    //   case catapultStates::loaded:
    //
    //   if(HIDMain.get_digital(DIGITAL_R2))
    //   {
    //     m_catapult.move(-127);
    //   }
    //
    //   else if(light_catapult.get_value_calibrated() < 70)
    //   {
    //     catapultState = catapultStates::tare;
    //   }
    //
    //   else
    //   {
    //     m_catapult.move(0);
    //   }
    //
    //   break;
    //
    //   case catapultState::tare:
    //
    //   m_catapult.move(-127);
    //
    //   if (m_catapult.getCurrentDraw() > ihavenoidea what this value is going to be)     //if current draw doesn't work use if(pot_catpult.get() > init_pot _catapult)
    //   {
    //     m_catapult.tarePosition();
    //
    //     catapultState = catapultStates::loading;
    //   }
    //
    //   break;
    // }
    pros::delay(20);
  }
}
