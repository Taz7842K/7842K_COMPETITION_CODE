#include "main.h"
#include "7842K_Main.h"

okapi::Motor m_frontLeft(1);
okapi::Motor m_frontRight(2);
okapi::Motor m_rearLeft(3);
okapi::Motor m_rearRight(4);

okapi::ChassisControllerPID skidBase = ChassisControllerFactory::create(
  {m_frontLeft,m_rearLeft} ,{m_frontRight,m_rearRight},
  IterativePosPIDController::Gains{0.0, 0.0, 0.0}, //distance PID
  IterativePosPIDController::Gains{0.0, 0.0, 0}, //Angle PID
  IterativePosPIDController::Gains{0.0, 0, 0}, //turning PID
  AbstractMotor::gearset::green,
  {4_in, 11.75_in}
);
