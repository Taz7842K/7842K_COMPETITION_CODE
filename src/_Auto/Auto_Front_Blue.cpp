#include "main.h"
#include "7842K_Main.h"

void autoFrontBlue()
{

m_lift1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
m_lift2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

PIDxBase.setMaxVelocity(125);

m_lift1.moveRelative(90,200);
m_lift2.moveRelative(90,200);

m_intake.move(-127);

PIDxBase.moveDistance(42_in);
pros::delay(500);

PIDxBase.setMaxVelocity(125);

PIDxBase.moveDistance(-40_in);
pros::delay(500);

PIDxBase.turnAngle(-90_deg);

PIDxBase.moveDistance(-18_in);

PIDxBase.setMaxVelocity(75);

PIDxBase.turnAngle(-10_deg);
pros::delay(100);

m_catapult.moveRelative(-100,200);
pros::delay(300);

PIDxBase.turnAngle(10_deg);
pros::delay(100);

m_intake.move(0);

PIDxBase.setMaxVelocity(150);

PIDxBase.moveDistance(30_in);
pros::delay(100);

PIDxBase.moveDistance(20_in);
pros::delay(100);

PIDxBase.turnAngle(90_deg);
pros::delay(100);

m_intake.move(127);

PIDxBase.moveDistance(30_in);
pros::delay(100);

}
