#include "main.h"
#include "7842K_Main.h"



bool firstPress = false;
bool firstRelease = false;
bool catapultToggle = false;
//-----------------------------Intake Control--------------------------------------------------------
void intakeControlTask()
{
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
}

//--------------------------Intake Control-----------------------------------------------------------

void driverControlTask()
{

  //--------------------------Catapult Control---------------------------------------------------------
  if(HIDMain.get_digital(DIGITAL_R2))
  {
    m_catapult.move(-127);
    catapultToggle = true;
  }

  else if(pot_catapult.get() < 2000)
  {
    m_catapult.move(-127);
  }

  else
  {
    m_catapult.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE);
    m_catapult.move(0);
  }
  //--------------------------Catapult Control---------------------------------------------------------

  //--------------------------LIft Control-------------------------------------------------------------
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
  //-------------------------Lift Control--------------------------------------------------------------
}
