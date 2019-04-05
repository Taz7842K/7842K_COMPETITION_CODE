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
  e_frontLeft, e_frontRight, e_rearRight, e_rearLeft,
  IterativePosPIDController::Gains{0.0027, 0.00001, 0.00025}, //distance PID
  IterativePosPIDController::Gains{0.0033, 0.0, 0}, //angle PID
  IterativePosPIDController::Gains{0.0033, 0.00001, 0.00025}, //turning PID
  AbstractMotor::gearset::green,
  {4_in, 22.15_in}
);
