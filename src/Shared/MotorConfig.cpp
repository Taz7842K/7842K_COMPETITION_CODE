#include "main.h"
#include "7842K_Main.h"

okapi::Motor m_frontLeft(9);
okapi::Motor m_frontRight(18);
okapi::Motor m_rearLeft(8);
okapi::Motor m_rearRight(7);

okapi::Motor m_intake(2);

okapi::Motor m_lift(4);

okapi::Motor m_catapult(6);

okapi::ChassisControllerPID skidBase = ChassisControllerFactory::create(
  {m_frontLeft, m_rearLeft}, {m_frontRight, m_rearRight},
  IterativePosPIDController::Gains{pGain, 0, dGain}, //distance PID
  IterativePosPIDController::Gains{0.001, 0.0, 0.001}, //Angle PID
  IterativePosPIDController::Gains{0.001, 0, 0.001}, //turning PID
  AbstractMotor::gearset::green,
  {4_in, 11.75_in}
);

double pGain = 0.001;
double dGain = 0.001;
