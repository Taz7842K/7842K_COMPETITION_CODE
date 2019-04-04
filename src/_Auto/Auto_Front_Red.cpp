#include "main.h"
#include "7842K_Main.h"

void autoFrontRed()
{
  // m_lift1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  // m_lift2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  liftState = liftStates::tinyLift;

  intakeState = intakeStates::forward;

  PIDxBase.moveDistance(42_in);

  pros::delay(500);

  PIDxBase.moveDistance(-42_in);

  intakeState = intakeStates::stopped;

  PIDxBase.turnAngle(90_deg);

  PIDxBase.moveDistance(-10_in);

  catapultState = catapultStates::trigger;

  while(catapultState == catapultStates::trigger){pros::delay(20);};

  PIDxBase.moveDistance(-42_in);

  PIDxBase.moveDistance(32_in);

  PIDxBase.turnAngle(-90_deg);
  pros::delay(100);

  intakeState = intakeStates::reverse;

  PIDxBase.moveDistance(40_in);

  intakeState = intakeStates::stopped;

}
