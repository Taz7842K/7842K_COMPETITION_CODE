#include "main.h"
#include "7842K_Main.h"

void auto_1()
{
  m_intake.move(-127);

  skidBase.moveDistance(42_in);               //Moves to grab ball under the cap
  pros::delay(200);                           //waits to grab ball

  m_intake.move(0);

  skidBase.turnAngle(-90_deg);

  skidBase.moveDistance(25_in);               //Placeholder value to put catapult in position

  skidBase.moveDistance(-10_in);              //Puts robot in place to knock over second cap

  skidBase.turnAngle(90_deg);

  skidBase.moveDistance(32_in);
}
