#include "main.h"
#include "7842K_Main.h"

void autoClose(lib7842::autonSides side)
{
  if(side == lib7842::autonSides::red)
  {
  skidBase.moveDistance(-25_in);               //Placeholder value to put catapult in position
  skidBase.moveDistance(42_in);
  skidBase.turnAngle(90_deg);
  }

  else if(side == lib7842::autonSides::blue)
  {

  }
}
