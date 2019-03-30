#include "main.h"
#include "7842K_Main.h"

void autoSkills(lib7842::autonSides)
{
  m_lift1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  m_lift2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  xBase.setMaxVelocity(125);

  m_lift1.moveRelative(90,200);                       // moves lift into place while driving forward
  m_lift2.moveRelative(90,200);

  m_intake.move(-127);

  xBase.moveDistance(42_in);                       //moves to grab ball under the cap
  pros::delay(500);

  xBase.setMaxVelocity(125);

  xBase.moveDistance(-40_in);                       //backs up in line with the flags
  pros::delay(500);

  xBase.turnAngle(90_deg);                       //turns toward the flags

  xBase.moveDistance(-18_in);                       //moves in place to shoot

  xBase.setMaxVelocity(75);

  xBase.turnAngle(10_deg);                       //aims at flags
  pros::delay(100);

  m_catapult.moveRelative(-100,200);                       //shoots flags
  pros::delay(300);

  xBase.turnAngle(-10_deg);
  pros::delay(100);

  m_intake.move(0);

  xBase.setMaxVelocity(150);

  xBase.moveDistance(-30_in);                       //hits low flags
  pros::delay(100);

  xBase.moveDistance(20_in);
  pros::delay(100);

  xBase.turnAngle(-90_deg);
  pros::delay(100);

  m_intake.move(127);

  xBase.moveDistance(30_in);
  pros::delay(100);

  xBase.moveDistance(-72_in);
  pros::delay(100);

  xBase.turnAngle(-90_deg);
  pros::delay(100);

  xBase.moveDistance(-70_in);
  pros::delay(100);
}
