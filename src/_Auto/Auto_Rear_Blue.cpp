#include "main.h"
#include "7842K_Main.h"

void autoRearBlue()
{
    pros::delay(500);

    PIDxBase.setMaxVelocity(125);
    //
    // m_lift1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    // m_lift2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    //
    // m_lift1.moveRelative(800,200);                      //brings down the lift
    // m_lift2.moveRelative(800,200);
    //
    PIDxBase.moveDistance(42_in);                      //drives toward cap
    pros::delay(100);

    PIDxBase.moveDistance(-11_in);
    pros::delay(100);

    PIDxBase.turnAngle(-90_deg);
    pros::delay(100);

    PIDxBase.moveDistance(-30_in);
    pros::delay(100);

    // m_lift1.moveRelative(-300,50);                      //picks up cap
    // m_lift2.moveRelative(-300,50);
    // pros::delay(600);
    //
    // PIDxBase.moveDistance(24_in);
    // pros::delay(100);
    //
    //
    // PIDxBase.turnAngle(130_deg);                      //turns toward post
    // pros::delay(100);
    //
    // PIDxBase.moveDistance(12_in);                      //backs up into post
    // pros::delay(100);
    //
    // m_frontLeft.moveVelocity(0);
    // m_frontRight.moveVelocity(0);
    // m_rearLeft.moveVelocity(0);
    // m_rearRight.moveVelocity(0);
    // pros::delay(100);
    //
    // m_lift1.moveRelative(-250,50);                      //places  cap on post
    // m_lift2.moveRelative(-250,50);
    // pros::delay(800);
    //
    // m_lift1.moveRelative(300,200);
    // m_lift2.moveRelative(300,200);
    //
    // PIDxBase.moveDistance(-20_in);                      //drives back from post while half unfolding lift
    // pros::delay(100);
    //
    // PIDxBase.turnAngle(-90_deg);
    // pros::delay(100);
    //
    // PIDxBase.setMaxVelocity(200);
    //
    // PIDxBase.moveDistance(-20_in);                      //knocks over other cap
    // pros::delay(50);
    //
    // PIDxBase.moveDistance(8_in);                      //backs up
    //
    // PIDxBase.turnAngle(95_deg);                      //turns toward platform
    // pros::delay(50);
    //
    // PIDxBase.moveDistance(-45_in);                      //drives onto platform
}
