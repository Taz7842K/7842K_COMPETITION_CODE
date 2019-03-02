#include "main.h"
#include "7842K_Main.h"

void autoRear(lib7842::autonSides side)
{
  if(side == lib7842::autonSides::red)
  {

        skidBase.setMaxVelocity(125);

        m_lift1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        m_lift2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

        m_lift1.moveRelative(800,200);
        m_lift2.moveRelative(800,200);

        skidBase.moveDistance(-45_in);
        pros::delay(100);

        m_lift1.moveRelative(-300,50);
        m_lift2.moveRelative(-300,50);
        pros::delay(600);

        skidBase.moveDistance(23_in);

        skidBase.turnAngle(-130_deg); //turns counter-clockwise

        skidBase.moveDistance(10_in);
        pros::delay(100);

        m_lift1.moveRelative(-250,50);
        m_lift2.moveRelative(-250,50);
        pros::delay(1200);

        skidBase.moveDistance(-25_in);

        skidBase.turnAngle(90_deg);

        skidBase.moveDistance(-20_in);

        skidBase.moveDistance(8_in);

        skidBase.turnAngle(90_deg);
  }

  else if(side == lib7842::autonSides::blue)
  {
            pros::delay(500);

            skidBase.setMaxVelocity(125);

            m_lift1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
            m_lift2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

            m_lift1.moveRelative(800,200);
            m_lift2.moveRelative(800,200);

            skidBase.moveDistance(-47_in);
            pros::delay(100);

            m_lift1.moveRelative(-300,50);
            m_lift2.moveRelative(-300,50);
            pros::delay(600);

            skidBase.moveDistance(24_in);

            skidBase.turnAngle(130_deg);

            skidBase.moveDistance(14_in);

            m_frontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
            m_frontRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
            m_rearLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
            m_rearRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
            m_frontLeft.moveVelocity(0);
            m_frontRight.moveVelocity(0);
            m_rearLeft.moveVelocity(0);
            m_rearRight.moveVelocity(0);
            pros::delay(100);

            m_lift1.moveRelative(-250,50);
            m_lift2.moveRelative(-250,50);
            pros::delay(800);

            m_frontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
            m_frontRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
            m_rearLeft.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
            m_rearRight.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);

            skidBase.moveDistance(-25_in);

            m_lift1.moveRelative(600,50);
            m_lift2.moveRelative(600,50);

            skidBase.turnAngle(-90_deg);

            skidBase.moveDistance(-20_in);

            skidBase.moveDistance(8_in);

            skidBase.turnAngle(90_deg);

            skidBase.setMaxVelocity(200);

            skidBase.moveDistance(-40_in);
  }
}
