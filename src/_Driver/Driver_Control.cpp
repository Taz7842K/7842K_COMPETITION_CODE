#include "main.h"
#include "7842K_Main.h"

state intake = OFF;
bool firstPress = false;
bool firstRelease = false;

//-----------------------------Intake Control--------------------------------------------------------
void intakeControlTask()
{

  if(HIDMain.get_digital(DIGITAL_A) && intake == OFF)
  {
    m_intake.move(127);
    firstPress = true;
  }

  // else if(HIDMain.get_digital(DIGITAL_B) && intake == OFF)
  // {
  //   m_intake.move(-127);
  //   firstPress = true;
  // }

  else if (!HIDMain.get_digital(DIGITAL_A) && firstPress == true)
  {
    intake = ON;
  }

  else if(HIDMain.get_digital(DIGITAL_A) && intake == ON)
  {
    m_intake.move(0);
    firstRelease = true;
  }

  // else if(HIDMain.get_digital(DIGITAL_B) && intake == ON)
  // {
  //   m_intake.move(0);
  //   firstRelease = true;
  // }

  else if (!HIDMain.get_digital(DIGITAL_A) && firstRelease == true)
  {
    intake = OFF;
    firstPress = false;
    firstRelease = false;
  }

  else
  {

  }
}

//--------------------------Intake Control-----------------------------------------------------------

void driverControlTask()
{

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
    m_lift1.move(127);
    m_lift2.move(127);
  }

  else if(HIDMain.get_digital(DIGITAL_DOWN))
  {
    m_lift1.move(-127);
    m_lift2.move(-127);
  }

  else
  {
    //   if(pot_armLift.get_analog() > vertical < far tipping point)
    //   {
    //     m_lift.move(-5);
    //   }
    //   else if(pot_armLift.get_analog() > vertical > far tipping point)
    //   {
    //     m_lift.move(-10);
    //   }
    // }
    //   else if(pot_armLift.get_analog() < vertical > close tipping point)
    //   {
    //     m_lift.move(5);
    //   }
    //   else if(pot_armLift.get_analog() < vertical < close tipping point)
    //   {
    //     m_lift.move(10);
    //   }
    m_lift1.move(0);
    m_lift2.move(0);
  }
  //-------------------------Lift Control--------------------------------------------------------------
}
