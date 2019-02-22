#include "main.h"
#include "7842K_Main.h"

void driverControlTask()
{

  //-----------------------------Intake Control--------------------------------------------------------
  if(HIDMain.get_digital(DIGITAL_L1))
  {
    m_intake.move(127);
  }
  else if(HIDMain.get_digital(DIGITAL_L2))
  {
    m_intake.move(-127);
  }
  else
  {
    m_intake.move(0);
  }
  //--------------------------Intake Control-----------------------------------------------------------

  //--------------------------Catapult Control---------------------------------------------------------
  // if(HIDMain.get_digital(DIGITAL_R1) && pot_catapult.get() < idontknow) //moves catapult into loading position
  // {
  //   m_catapult.move(-127);
  // }

  if(HIDMain.get_digital(DIGITAL_R2))                             //shoots catapult and provides manual control
  {
    m_catapult.move(-127);
  }

  else
  {
    m_catapult.move(0);
  }
  //--------------------------Catapult Control---------------------------------------------------------
}
