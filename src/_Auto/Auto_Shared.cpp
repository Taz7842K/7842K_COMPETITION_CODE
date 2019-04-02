#include "main.h"
#include "7842K_Main.h"

void autoFront(lib7842::autonSides side)
{
  if(side == lib7842::autonSides::red)
  {
    autoFrontRed();
  }

  else if(side == lib7842::autonSides::blue)
  {
    autoFrontBlue();
  }
}

void autoRear(lib7842::autonSides side)
{
  if(side == lib7842::autonSides::red)
  {
    autoRearRed();
  }

  else if(side == lib7842::autonSides::blue)
  {
    autoRearBlue();
  }
}
