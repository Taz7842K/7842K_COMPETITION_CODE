#include "main.h"
#include "7842K_Main.h"

//--------------Initialize--------------------------------------------
void initialize()
{
  light_capDetect.calibrate();
}

// -------------Initialize---------------------------------------------

//--------------Disabled-----------------------------------------------
void disabled()
{

}
//--------------Disabled-----------------------------------------------

//--------------Competition Initialize---------------------------------
void competition_initialize() {}
//--------------Competition Initialize---------------------------------

//--------------Autonomous---------------------------------------------
void autonomous()
{
  auto_1();
}
//--------------Autonomous---------------------------------------------

//-------------opControl-----------------------------------------------
void opcontrol()
{
  while (true)
  {
  std::cout << "light_capDetect =" << light_capDetect.get_value_calibrated() << std::endl;
pros::delay(200);
  }
}
//------------opControl------------------------------------------------
