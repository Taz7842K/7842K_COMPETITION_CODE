#include "main.h"
#include "7842K_Main.h"

//--------------Initialize--------------------------------------------
void initialize()
{
  pros::Task t_coutTask(coutTask);

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
  autonSelector.run();
}
//--------------Autonomous---------------------------------------------

//-------------opControl-----------------------------------------------
void opcontrol()
{
  pros::delay(100);

  while(true)
  {
    driverControlTask();
    intakeControlTask();
    baseControlTask();

    // if(HIDMain.get_digital(DIGITAL_LEFT))
    // {
    //   autoFront(lib7842::autonSides::red);
    // }

    pros::delay(50);
  }
}
//------------opControl------------------------------------------------

void coutTask(void*)
{
  while(true)
  {
    std::cout <<"m_lift1 = " <<m_lift1.getPosition()<<std::endl;
    std::cout <<"pot_catapult = " <<pot_catapult.get()<<std::endl;
    std::cout <<"m_catapult Temperature" <<m_catapult.getTemperature()<<std::endl;
    std::cout <<"m_catapult voltage" <<m_catapult.getVoltage()<<std::endl;
    std::cout <<"sw_catapult = "<<sw_catapult.get_value()<<std::endl;

    // if(HIDMain.get_digital(DIGITAL_DOWN))
    // {
    //   exit(0);
    //   std::cout <<"Program Stopped?"<<std::endl;
    // }

    pros::delay(500);
  }
}
