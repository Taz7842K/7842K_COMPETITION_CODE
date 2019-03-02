#include "main.h"
#include "7842K_Main.h"

state intake = OFF;
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
  //
  // if(HIDMain.get_digital(DIGITAL_R2))                             //shoots catapult and provides manual control
  // {
  //   m_catapult.move(-127);
  //   catapultToggle = false;
  // }
  //
  // else if(pot_catapult.get() < 1253 && catapultToggle == false)
  // {
  //   m_catapult.move(-127);
  //
  //   if(pot_catapult.get() > 1248)
  //   {
  //     m_catapult.move(0);
  //     catapultToggle = true;
  //   }
  // }
  //
  // else
  // {
  //   m_catapult.move(0);
  // }

  if(HIDMain.get_digital(DIGITAL_R2))                             //shoots catapult and provides manual control
  {
    m_catapult.move(-127);
  }

  else if(pot_catapult.get() < 1250)
  {
    m_catapult.move(-127);
  }

  else if(pot_catapult.get() > 1240)
  {
    m_catapult.move(0);
  }

  else
  {
    m_catapult.move(0);
}
  //--------------------------Catapult Control---------------------------------------------------------

  //--------------------------LIft Control-------------------------------------------------------------
  // if(HIDMain.get_digital(DIGITAL_L2))                   //Moves lift down
  // {
  //   double liftPower = 127 - abs(m_lift1.getPosition() /810 * 127 + 50);
  //   m_lift1.move(liftPower);
  //   m_lift2.move(liftPower);
  // }
  //
  // else if(HIDMain.get_digital(DIGITAL_L1))              //Moves lift up
  // {
  //   double liftPower = (127 - abs(m_lift1.getPosition() /810 * 127 + 50)) * -1;
  //   m_lift1.move(liftPower);
  //   m_lift2.move(liftPower);
  // }
  //
  // else
  // {
  //   m_lift1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  //   m_lift2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  //   m_lift1.moveVelocity(0);
  //   m_lift2.moveVelocity(0);
  // }
  //
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
