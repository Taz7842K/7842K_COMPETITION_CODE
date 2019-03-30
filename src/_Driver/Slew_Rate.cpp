#include "main.h"
#include "7842K_Main.h"

void slewRate(int slewRate)
{
  powerError = wantedPower - actualPower;

  if(powerError) > slewRate)
  {
    if(powerError > 0)
    {
      actualPower = actualPower + slewRate;
    }
    else
    {
      actualPower = actualPower - slewRate;
    }
  }

  else
  {
    actualPower = wantedPower;
  }

  if(actualPower == 0)
  {
    m_lift1.moveVelocity(0);
  }
  else {
    m_lift1.move(actualPower);
    m_lift2.move(actualPower);
  }

  pros::delay(20);
}
