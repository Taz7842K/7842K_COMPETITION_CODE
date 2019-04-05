#include "main.h"
#include "7842K_Main.h"

double wantedPower = 0;
double actualPower = 0;
double powerError = 0;

liftStates liftState = liftStates::driver;

void liftControlTask(void*)
{
  m_lift1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  m_lift2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  while (true)
  {

    switch(liftState)
    {

      case liftStates::driver:

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
        m_lift1.moveVelocity(0);
        m_lift2.moveVelocity(0);
      }

      break;

      case liftStates::stopped:

      m_lift1.moveVelocity(0);
      m_lift2.moveVelocity(0);

      break;

      case liftStates::tinyLift:

      m_lift1.moveAbsolute(70,100);
      m_lift2.moveAbsolute(70,100);

      while(m_lift1.getTargetPosition() > m_lift1.getPosition() + 5){pros::delay(20);};

      liftState = liftStates::stopped;

      break;

      case liftStates::unfold:

      m_lift1.moveAbsolute(760,100);
      m_lift2.moveAbsolute(760,100);

      while(m_lift1.getTargetPosition() > m_lift1.getPosition() + 10){pros::delay(20);};

      liftState = liftStates::stopped;

      break;

      case liftStates::placeCap:

      m_lift1.moveAbsolute(230,100);
      m_lift2.moveAbsolute(230,100);

      while(m_lift1.getTargetPosition() < m_lift1.getPosition() - 10){pros::delay(20);};

      liftState = liftStates::stopped;

      break;

      case liftStates::holdCap:

      m_lift1.moveAbsolute(600,100);
      m_lift2.moveAbsolute(600,100);

      if(m_lift1.getTargetPosition() > m_lift1.getPosition())
      {
        while(m_lift1.getTargetPosition() > m_lift1.getPosition() + 10){pros::delay(20);};

        liftState = liftStates::stopped;
      }

      else if(m_lift1.getTargetPosition() < m_lift1.getPosition())
      {
        while(m_lift1.getTargetPosition() < m_lift1.getPosition() - 10){pros::delay(20);};

        liftState = liftStates::stopped;
      }

      break;
    }

    pros::delay(20);

  }
}
