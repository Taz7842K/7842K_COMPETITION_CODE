#include "main.h"
#include "7842K_Main.h"

void autoFront(lib7842::autonSides side)
{
  if(side == lib7842::autonSides::red)
  {

  }

  else if(side == lib7842::autonSides::blue)
  {
    skidBase.setMaxVelocity(100);

    m_intake.move(-80);

    driveFullPower(10);
    slowStop(6_in);

    pros::delay(200);

    driveFullPowerReverse(32);
    slowStop(6_in);

    skidBase.turnAngle(90_deg);

    // m_catapult.moveRelative(-50,200);
    // while(!m_catapult.isStopped()){pros::delay(10);}

    // m_catapult.moveRelative(-360,200);

    skidBase.moveDistance(-8_in);

    // while(pot_catapult.get() < 1245 ){m_catapult.move(-127); pros::delay(10);}

    driveFullPower(34);
    slowStop(2_in);

    skidBase.turnAngle(-45);

    slowStop(6_in);

    // m_catapult.moveRelative(-50,200);
    // while(!m_catapult.isStopped()){pros::delay(10);}

    driveFullPower(6);
  }
}
