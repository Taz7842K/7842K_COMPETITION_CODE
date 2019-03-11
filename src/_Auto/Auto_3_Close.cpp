#include "main.h"
#include "7842K_Main.h"

void autoFront(lib7842::autonSides side)
{
  if(side == lib7842::autonSides::red)
  {
    m_lift1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    m_lift2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    skidBase.setMaxVelocity(125);

    m_lift1.moveRelative(90,200);
    m_lift2.moveRelative(90,200);

    m_intake.move(-127);

    skidBase.moveDistance(42_in);
    pros::delay(500);

    skidBase.setMaxVelocity(125);

    skidBase.moveDistance(-40_in);
    pros::delay(500);

    skidBase.turnAngle(90_deg);

    skidBase.moveDistance(-18_in);

    skidBase.setMaxVelocity(75);

    skidBase.turnAngle(10_deg);
    pros::delay(100);

    m_catapult.moveRelative(-100,200);
    pros::delay(300);

    skidBase.turnAngle(-10_deg);
    pros::delay(100);

    m_intake.move(0);

    skidBase.setMaxVelocity(150);

    skidBase.moveDistance(-30_in);
    pros::delay(100);

    skidBase.moveDistance(20_in);
    pros::delay(100);

    skidBase.turnAngle(-90_deg);
    pros::delay(100);

    m_intake.move(127);

    skidBase.moveDistance(30_in);
    pros::delay(100);
  }

  else if(side == lib7842::autonSides::blue)
  {
    m_lift1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    m_lift2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    skidBase.setMaxVelocity(125);

    m_lift1.moveRelative(90,200);
    m_lift2.moveRelative(90,200);

    m_intake.move(-127);

    skidBase.moveDistance(42_in);
    pros::delay(500);

    skidBase.setMaxVelocity(125);

    skidBase.moveDistance(-40_in);
    pros::delay(500);

    skidBase.turnAngle(-90_deg);

    skidBase.moveDistance(-18_in);

    skidBase.setMaxVelocity(75);

    skidBase.turnAngle(-10_deg);
    pros::delay(100);

    m_catapult.moveRelative(-100,200);
    pros::delay(300);

    skidBase.turnAngle(10_deg);
    pros::delay(100);

    m_intake.move(0);

    skidBase.setMaxVelocity(150);

    skidBase.moveDistance(30_in);
    pros::delay(100);

    skidBase.moveDistance(20_in);
    pros::delay(100);

    skidBase.turnAngle(90_deg);
    pros::delay(100);

    m_intake.move(127);

    skidBase.moveDistance(30_in);
    pros::delay(100);
  }
}
