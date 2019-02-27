#include "main.h"
#include "7842K_Main.h"

okapi::Motor m_frontLeft(9);
okapi::Motor m_frontRight(18);
okapi::Motor m_rearLeft(8);
okapi::Motor m_rearRight(7);

okapi::Motor m_intake(2);

okapi::Motor m_lift1(-14);
okapi::Motor m_lift2(15);

okapi::Motor m_catapult(6);

lib7842::AutonSelector autonSelector(lv_scr_act(), {{"Disabled", autoNothing},{"Skills", autoSkills},{"Front", autoFront},{"Rear", autoRear}});

okapi::ChassisControllerIntegrated skidBase = ChassisControllerFactory::create(
  {8, 9}, {-18, -7},
  AbstractMotor::gearset::green,
  {4_in, 11.35_in}
);
