#include "main.h"
#include "7842K_Main.h"

void autoFrontBlue()
{
  liftState = liftStates::tinyLift;

  intakeState = intakeStates::forward;

  PIDxBase.moveDistance(45_in);

  pros::delay(500);

  PIDxBase.moveDistance(-45_in);

  intakeState = intakeStates::stopped;

  PIDxBase.turnAngle(-90_deg);

  PIDxBase.moveDistance(-10_in);

  catapultState = catapultStates::trigger;

  while(catapultState == catapultStates::trigger){pros::delay(20);};

  PIDxBase.turnAngle(5_deg);

  PIDxBase.moveDistance(-42_in);

  PIDxBase.moveDistance(29_in);

  PIDxBase.turnAngle(85_deg);
  pros::delay(100);

  intakeState = intakeStates::reverse;

  PIDxBase.moveDistance(40_in);

  PIDxBase.turnAngle(-60_deg);

  intakeState = intakeStates::stopped;

  PIDxBase.moveDistance(25_in);

}
