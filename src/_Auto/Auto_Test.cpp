#include "main.h"
#include "7842K_Main.h"

void autoTest(lib7842::autonSides)
{
  PIDxBase.moveDistance(42_in);

  PIDxBase.moveDistance(-42_in);

  PIDxBase.turnAngle(-90_deg);
}
