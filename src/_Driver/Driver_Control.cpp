#include "main.h"
#include "7842K_Main.h"

intakeStates intakeState = intakeStates::driver;
catapultStates catapultState = catapultStates::loaded;

//-----------------------------Intake Control--------------------------------------------------------
void intakeControlTask(void*)
{
  while (true)
  {
    switch(intakeState)
    {
      case intakeStates::reverse:
      m_intake.move(127);
      break;

      case intakeStates::forward:
      m_intake.move(127);
      break;

      case intakeStates::stopped:
      m_intake.move(0);
      break;

      case intakeStates::driver:

      if(HIDMain.get_digital(DIGITAL_B))
      {
        m_intake.move(127);
      }

      else if(HIDMain.get_digital(DIGITAL_R1))
      {
        m_intake.move(-127);
      }

      else
      {
        m_intake.move(0);
      }

      break;
    }

  }
  pros::delay(20);
}
//--------------------------Intake Control-----------------------------------------------------------
//--------------------------Catapult Control---------------------------------------------------------
void catapultControlTask(void*)
{
  m_catapult.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);

  while(true)
  {

    switch (catapultState)
    {
      case catapultStates::loading:

      m_catapult.move(-127);

      if (light_catapult.get_value_calibrated() < 700)
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

      else if(light_catapult.get_value_calibrated() > 800)
      {
        catapultState = catapultStates::loading;
      }

      else
      {
        m_catapult.move(0);
      }

      break;
    }
  }
  pros::delay(20);
}
//--------------------------Catapult Control---------------------------------------------------------

//--------------------------LIft Control-------------------------------------------------------------
void liftControlTask(void*)
{
  while (true)
  {
    if(HIDMain.get_digital(DIGITAL_L2))                   //Moves lift down
    {
      m_lift1.move(70);
      m_lift2.move(70);
    }

    else if(HIDMain.get_digital(DIGITAL_L1))              //Moves lift up
    {
      m_lift1.move(-70);
      m_lift2.move(-70);
    }

    else
    {
      m_lift1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      m_lift2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
      m_lift1.moveVelocity(0);
      m_lift2.moveVelocity(0);
    }
  }
  pros::delay(20);
}
//-------------------------Lift Control--------------------------------------------------------------
