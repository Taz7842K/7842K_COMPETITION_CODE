#include "main.h"
#include "7842K_Main.h"

void autoRearBlue()
{
  liftState = liftStates::unfold;

  pros::delay(300);

  PIDxBase.moveDistance(-45_in);

  liftState = liftStates::holdCap;

  PIDxBase.turnAngle(20_deg);

  PIDxBase.moveDistance(43_in);

  liftState = liftStates::placeCap;

  pros::delay(200);

  PIDxBase.moveDistance(-5_in);

  liftState = liftStates::holdCap;

  PIDxBase.turnAngle(30_deg);

  strafeRight(35);

  PIDxBase.moveDistance(-50_in);
}
