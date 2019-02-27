#include "main.h"
#include "7842K_Main.h"

void autoRear(lib7842::autonSides side)
{
  if(side == lib7842::autonSides::red)
  {
    skidBase.moveDistance(10);

    m_lift1.moveRelative(400,200);
    m_lift2.moveRelative(400,200);

    driveFullPower(26);
    slowStop(6_in);

    skidBase.turnAngle(-90);

    skidBase.moveDistance(10_in);

    
  }

  else if(side == lib7842::autonSides::blue)
  {

  }
}
