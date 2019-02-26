#include "main.h"
#include "7842K_Main.h"

void autoFront(lib7842::autonSides side)
{
  if(side == lib7842::autonSides::red)
  {
  skidBase.moveDistance(42_in);
  skidBase.turnAngle(90_deg);
  }

  else if(side == lib7842::autonSides::blue)
  {

  }
}
