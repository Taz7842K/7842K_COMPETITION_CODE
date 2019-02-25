#include "main.h"
#include "7842K_Main.h"

//--------------Initialize--------------------------------------------
void initialize()
{
  pros::Task cout_Task(coutTask);


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
  //auto_1();
}
//--------------Autonomous---------------------------------------------

//-------------opControl-----------------------------------------------
void opcontrol()
{
  while(true)
  {
  driverControlTask();
  baseControlTask();

  if(HIDMain.get_digital(DIGITAL_Y))
  {
    autonSelector.run();
    pros::delay(500000);
  }

  pros::delay(50);
  }
}
//------------opControl------------------------------------------------

void coutTask(void*)
{
  while(true)
  {
    std::cout <<"pot_armLift = " <<pot_armLift.get()<<std::endl;
    std::cout <<"pot_armFlip = " <<pot_capFlipper.get()<<std::endl;
    std::cout <<"pot_catapult = " <<pot_catapult.get()<<std::endl;
    pros::delay(500);
  }
}
