#include "main.h"
#include "7842K_Main.h"

int e_frontLeft = 9;
int e_frontRight = 18;
int e_rearLeft = 8;
int e_rearRight = 7;

okapi::MotorGroup leftChassis({e_frontLeft, e_rearLeft});
okapi::MotorGroup rightChassis({e_frontRight, e_rearRight});

okapi::Motor m_intake(2);

okapi::Motor m_lift(4);

okapi::Motor m_catapult(6);

float chassisWidth = 11.75;

okapi::ChassisControllerPID skidBase = ChassisControllerFactory::create(
  leftChassis, rightChassis,
  IterativePosPIDController::Gains{0.0, 0.0, 0.0}, //distance PID
  IterativePosPIDController::Gains{0.0, 0.0, 0}, //Angle PID
  IterativePosPIDController::Gains{0.0, 0, 0}, //turning PID
  AbstractMotor::gearset::green,
  {4_in, 11.75_in}
);
