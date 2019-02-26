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
  intakeControlTask();
  baseControlTask();

  if(HIDMain.get_digital(DIGITAL_LEFT))
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
    std::cout <<"m_catapult = " <<m_catapult.getPosition()<<std::endl;
    pros::delay(500);
  }
}
