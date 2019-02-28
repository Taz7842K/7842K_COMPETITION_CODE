#include "main.h"
#include "7842K_Main.h"

//--------------Initialize--------------------------------------------
void initialize()
{
  pros::Task t_coutTask(coutTask);
  pros::Task t_killTask(killTask);

  m_lift1.tarePosition();
  m_lift2.tarePosition();
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

void killTask(void*)
{
  while(true)
  {
    if(HIDMain.get_digital(DIGITAL_DOWN))
    {
      exit(0);
      std::cout <<"Program Stopped?"<<std::endl;
    }

    pros::delay(20);
  }
}
