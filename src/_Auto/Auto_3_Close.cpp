#include "main.h"
#include "7842K_Main.h"

void autoFront(lib7842::autonSides side)
{
  if(side == lib7842::autonSides::red)
  {
    skidBase.setMaxVelocity(125);

    m_intake.move(-80);

    driveFullPower(36);
    slowStop(6_in);

    pros::delay(200);

    skidBase.moveDistance(-39_in);
    pros::delay(movDel);

    driveArcRight(30, 15);

    skidBase.turnAngle(90_deg);
    pros::delay(movDel);
  }

  else if(side == lib7842::autonSides::blue)
  {

  }
}
