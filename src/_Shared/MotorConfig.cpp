#include "main.h"
#include "7842K_Main.h"

int8_t e_frontLeft(9);
int8_t e_frontRight(-13);
int8_t e_rearLeft(4);
int8_t e_rearRight(-7);

okapi::Motor m_frontLeft(abs(e_frontLeft));
okapi::Motor m_frontRight(abs(e_frontRight));
okapi::Motor m_rearLeft(abs(e_rearLeft));
okapi::Motor m_rearRight(abs(e_rearRight));

okapi::Motor m_intake(2);

okapi::Motor m_lift1(-14);
okapi::Motor m_lift2(15);

okapi::Motor m_catapult(6);

lib7842::AutonSelector autonSelector(lv_scr_act(), {{"Disabled", autoNothing},{"Skills", autoSkills},{"Front", autoFront},{"Rear", autoRear}, {"Test", autoTest}});

okapi::ChassisControllerPID PIDxBase = ChassisControllerFactory::create(
  {e_frontLeft, e_rearRight}, {e_frontRight, e_rearRight},
  IterativePosPIDController::Gains{0.0001, 0, 0.001}, //distance PID
  IterativePosPIDController::Gains{0.001, 0, 0.00}, //angle PID
  IterativePosPIDController::Gains{0.00, 0, 0.000}, //turning PID
  AbstractMotor::gearset::green,
  {4_in, 11.25_in}
);

okapi::ChassisControllerIntegrated xBase = ChassisControllerFactory::create(
  e_frontLeft, e_rearRight, e_frontRight, e_rearRight,
  AbstractMotor::gearset::green,
  {4_in, 11.25_in}
);
