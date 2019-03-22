#include "main.h"
#include "7842K_Main.h"

void autoTest(lib7842::autonSides)
{
  PIDxBase.moveDistance(15_in);
  PIDxBase.waitUntilSettled();

  PIDxBase.turnAngle(180_deg);
  PIDxBase.waitUntilSettled();

  PIDxBase.moveDistance(15_in);
  PIDxBase.waitUntilSettled();
}
