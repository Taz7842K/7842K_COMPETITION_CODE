#include "main.h"
#include "7842K_Main.h"

bool intakeOn = false;

void driverControlTask()
{

  //-----------------------------Intake Control--------------------------------------------------------
  if((intakeOn = false) && HIDMain.get_digital(DIGITAL_A))
  {
    intakeOn = true;
    m_intake.move(127);
  }
  else if((intakeOn = true) && HIDMain.get_digital(DIGITAL_B))
  {
    intakeOn = false;
    m_intake.move(0);
  }


  //--------------------------Intake Control-----------------------------------------------------------

  //--------------------------Catapult Control---------------------------------------------------------
  if(HIDMain.get_digital(DIGITAL_R1) && pot_catapult.get() < 1250) //moves catapult into loading position
  {
    m_catapult.move(-127);
  }

  else if(HIDMain.get_digital(DIGITAL_R2))                             //shoots catapult and provides manual control
  {
    m_catapult.move(-127);
  }

  else
  {
    m_catapult.move(0);
  }
  //--------------------------Catapult Control---------------------------------------------------------

  //--------------------------LIft Control-------------------------------------------------------------
  if(HIDMain.get_digital(DIGITAL_UP))
  {
    m_lift.move(127);
  }

  else if(HIDMain.get_digital(DIGITAL_DOWN))
  {
    m_lift.move(-127);
  }

  else
  {
    m_lift.move(0);
  }
  //-------------------------Lift Control--------------------------------------------------------------
}
