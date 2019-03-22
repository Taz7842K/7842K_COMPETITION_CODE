#include "main.h"
#include "7842K_Main.h"

void autoFront(lib7842::autonSides side)
{
  if(side == lib7842::autonSides::red)
  {
    m_lift1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    m_lift2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    xBase.setMaxVelocity(125);

    m_lift1.moveRelative(90,200);
    m_lift2.moveRelative(90,200);

    m_intake.move(-127);

    xBase.moveDistance(42_in);
    pros::delay(500);

    xBase.setMaxVelocity(125);

    xBase.moveDistance(-40_in);
    pros::delay(500);

    xBase.turnAngle(90_deg);

    xBase.moveDistance(-18_in);

    xBase.setMaxVelocity(75);

    xBase.turnAngle(10_deg);
    pros::delay(100);

    m_catapult.moveRelative(-100,200);
    pros::delay(300);

    xBase.turnAngle(-10_deg);
    pros::delay(100);

    m_intake.move(0);

    xBase.setMaxVelocity(150);

    xBase.moveDistance(-30_in);
    pros::delay(100);

    xBase.moveDistance(20_in);
    pros::delay(100);

    xBase.turnAngle(-90_deg);
    pros::delay(100);

    m_intake.move(127);

    xBase.moveDistance(30_in);
    pros::delay(100);
  }

  else if(side == lib7842::autonSides::blue)
  {
    m_lift1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    m_lift2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    xBase.setMaxVelocity(125);

    m_lift1.moveRelative(90,200);
    m_lift2.moveRelative(90,200);

    m_intake.move(-127);

    xBase.moveDistance(42_in);
    pros::delay(500);

    xBase.setMaxVelocity(125);

    xBase.moveDistance(-40_in);
    pros::delay(500);

    xBase.turnAngle(-90_deg);

    xBase.moveDistance(-18_in);

    xBase.setMaxVelocity(75);

    xBase.turnAngle(-10_deg);
    pros::delay(100);

    m_catapult.moveRelative(-100,200);
    pros::delay(300);

    xBase.turnAngle(10_deg);
    pros::delay(100);

    m_intake.move(0);

    xBase.setMaxVelocity(150);

    xBase.moveDistance(30_in);
    pros::delay(100);

    xBase.moveDistance(20_in);
    pros::delay(100);

    xBase.turnAngle(90_deg);
    pros::delay(100);

    m_intake.move(127);

    xBase.moveDistance(30_in);
    pros::delay(100);
  }
}
