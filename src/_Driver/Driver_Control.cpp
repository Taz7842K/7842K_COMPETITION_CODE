#include "main.h"
#include "7842K_Main.h"

state intake = OFF;
bool firstPress = false;
bool firstRelease = false;
bool catapultToggle;
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
  if(HIDMain.get_digital(DIGITAL_A))
  {
    catapultToggle = true;
  }

  if(catapultToggle == true && pot_catapult.get() < 1245)
  {
    m_catapult.move(-127);
  }

  else if(catapultToggle == true && pot_catapult.get() > 1242 )
  {
    m_catapult.move(0);
  }

  else if(HIDMain.get_digital(DIGITAL_R2))                             //shoots catapult and provides manual control
  {
    m_catapult.move(-127);
    catapultToggle = false;
  }

  else
  {
    m_catapult.move(0);
  }
  //--------------------------Catapult Control---------------------------------------------------------

  //--------------------------LIft Control-------------------------------------------------------------
  if(HIDMain.get_digital(DIGITAL_L2))
  {
    m_lift1.move(50);
    m_lift2.move(50);
  }

  else if(HIDMain.get_digital(DIGITAL_L1))
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
