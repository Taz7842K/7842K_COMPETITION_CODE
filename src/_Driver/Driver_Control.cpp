#include "main.h"
#include "7842K_Main.h"

state intake = OFF;

void driverControlTask()
{

  //-----------------------------Intake Control--------------------------------------------------------
  if(HIDMain.get_digital(DIGITAL_A) && state intake = OFF)
  {
    m_intake.move(127);
    static bool firstPress = true;
  }

  else if(HIDMain.get_digital(DIGITAL_B) && state intake = OFF)
  {
    m_intake.move(-127);
    firstPress = true;
  }

  else if (HIDMain.get_digital(DIGITAL_A) = 0 && firstPress = true)
  {
    state intake = ON;
  }

  else if(HIDMain.get_digital(DIGITAL_A) && state intake = ON)
  {
    m_intake.move(0);
    static bool firstRelease = true;
  }

  else if(HIDMain.get_digital(DIGITAL_B) && state intake = ON)
  {
    m_intake.move(0);
    firstRelease = true;
  }

  else if (HIDMain.get_digital(DIGITAL_A) = 0 && firstRelease = true)
  {
    state intake = OFF;
  }


  //--------------------------Intake Control-----------------------------------------------------------

  //--------------------------Catapult Control---------------------------------------------------------
  if(HIDMain.get_digital(DIGITAL_R1) && pot_catapult.get() < 1245) //moves catapult into loading position
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
    if(pot_armLift.get_analog() > vertical < far tipping point)
    {
      m_lift.move(-5);
    }
    else if(pot_armLift.get_analog() > vertical > far tipping point)
    {
      m_lift.move(-10);
    }
  }
    else if(pot_armLift.get_analog() < vertical > close tipping point)
    {
      m_lift.move(5);
    }
    else if(pot_armLift.get_analog() < vertical < close tipping point)
    {
      m_lift.move(10);
    }

  //-------------------------Lift Control--------------------------------------------------------------
}
