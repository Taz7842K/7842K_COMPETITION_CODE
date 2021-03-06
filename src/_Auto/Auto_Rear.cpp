#include "main.h"
#include "7842K_Main.h"

void autoRear(lib7842::autonSides side)
{
  if(side == lib7842::autonSides::red)
  {
    pros::delay(500);

    skidBase.setMaxVelocity(125);

    m_lift1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    m_lift2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    m_lift1.moveRelative(800,200);                      //brings down the lift
    m_lift2.moveRelative(800,200);

    skidBase.moveDistance(-47_in);                      //drives toward cap
    pros::delay(100);

    m_lift1.moveRelative(-300,50);                      //picks up cap
    m_lift2.moveRelative(-300,50);
    pros::delay(600);

    skidBase.moveDistance(22_in);
    pros::delay(100);


    skidBase.turnAngle(-135_deg);                      //turns toward post
    pros::delay(100);

    skidBase.moveDistance(9_in);                      //backs up into post
    pros::delay(100);

    m_frontLeft.moveVelocity(0);
    m_frontRight.moveVelocity(0);
    m_rearLeft.moveVelocity(0);
    m_rearRight.moveVelocity(0);
    pros::delay(100);

    m_lift1.moveRelative(-250,50);                      //places  cap on post
    m_lift2.moveRelative(-250,50);
    pros::delay(800);

    m_lift1.moveRelative(400,200);
    m_lift2.moveRelative(400,200);

    skidBase.moveDistance(-25_in);                      //drives back from post while half unfolding lift
    pros::delay(100);

    skidBase.turnAngle(90_deg);
    pros::delay(100);

    skidBase.setMaxVelocity(200);

    skidBase.moveDistance(-20_in);                      //knocks over other cap
    pros::delay(100);

    skidBase.moveDistance(8_in);                      //backs up

    skidBase.turnAngle(-90_deg);                      //turns toward platform
    pros::delay(100);

    skidBase.moveDistance(-40_in);
  }

  else if(side == lib7842::autonSides::blue)
  {
    pros::delay(500);

    skidBase.setMaxVelocity(125);

    m_lift1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    m_lift2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    m_lift1.moveRelative(800,200);                      //brings down the lift
    m_lift2.moveRelative(800,200);

    skidBase.moveDistance(-47_in);                      //drives toward cap
    pros::delay(100);

    m_lift1.moveRelative(-300,50);                      //picks up cap
    m_lift2.moveRelative(-300,50);
    pros::delay(600);

    skidBase.moveDistance(22_in);
    pros::delay(100);


    skidBase.turnAngle(135_deg);                      //turns toward post
    pros::delay(100);

    skidBase.moveDistance(9_in);                      //backs up into post
    pros::delay(100);

    m_frontLeft.moveVelocity(0);
    m_frontRight.moveVelocity(0);
    m_rearLeft.moveVelocity(0);
    m_rearRight.moveVelocity(0);
    pros::delay(100);

    m_lift1.moveRelative(-250,50);                      //places  cap on post
    m_lift2.moveRelative(-250,50);
    pros::delay(800);

    m_lift1.moveRelative(400,200);
    m_lift2.moveRelative(400,200);

    skidBase.moveDistance(-25_in);                      //drives back from post while half unfolding lift
    pros::delay(100);

    skidBase.turnAngle(-90_deg);
    pros::delay(100);

    skidBase.setMaxVelocity(200);

    skidBase.moveDistance(-20_in);                      //knocks over other cap
    pros::delay(100);

    skidBase.moveDistance(8_in);                      //backs up

    skidBase.turnAngle(90_deg);                      //turns toward platform
    pros::delay(100);

    skidBase.moveDistance(-40_in);                      //drives onto platform
  }
}
