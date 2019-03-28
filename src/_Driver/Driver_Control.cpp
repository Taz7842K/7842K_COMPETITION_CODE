#include "main.h"
#include "7842K_Main.h"

//-----------------------------Intake Control--------------------------------------------------------
void intakeControlTask()
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

  
  break;

  else
  {
    m_intake.move(0);
  }
}

//--------------------------Intake Control-----------------------------------------------------------
//--------------------------Catapult Control---------------------------------------------------------
void catapultControlTask()
{
  switch (catapultState)
  {
    case catapultStates::loading:

    while (pot_catapult.get() < 2230)
    {
      m_catapult.move(-127);
    }

    catapultState = catapultStates::loaded;

    break;

    case catapultStates::loaded:

    if(HIDMain.get_digital(DIGITAL_R2))                             //shoots catapult and provides manual control
    {
      m_catapult.move(-127);
    }

    else if(pot_catapult.get() < 1000)
    {
      catapultState = catapultStates::loading;
    }

    break;
  }




  else
  {
    m_catapult.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    m_catapult.move(0);
  }
}
//--------------------------Catapult Control---------------------------------------------------------

//--------------------------LIft Control-------------------------------------------------------------
void liftControlTask()
{

  if(HIDMain.get_digital(DIGITAL_L2))                   //Moves lift down
  {
    // double liftPower = abs(m_lift1.getPosition() /fullrange * 127);
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
//-------------------------Lift Control--------------------------------------------------------------
