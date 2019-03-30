#include "main.h"
#include "7842K_Main.h"

pros::Task* intakeControlTask_t = nullptr;
pros::Task* catapultControlTask_t = nullptr;
pros::Task* liftControlTask_t = nullptr;
pros::Task* baseControlTask_t = nullptr;

pros::Task* coutTask_t = nullptr;

//--------------Initialize--------------------------------------------
void initialize()
{
  m_lift1.tarePosition();
  m_lift2.tarePosition();

  initPotCatapult = pot_catapult.get();

  light_catapult.calibrate();

  // if (pot_catapult.get() > 1000)
  // {
  // initPotCatapult = pot_catapult.get() + 710;                      //1028 is full range of motion for catapult arm in potentiometer units
  // }
  // else if (pot_catapult.get() > 1000)
  // {
  //   initPotCatapult = pot_catapult.get();
  // }

  intakeControlTask_t = new pros::Task(intakeControlTask);
  catapultControlTask_t = new pros::Task(catapultControlTask);

  coutTask_t = new pros::Task(coutTask);
}

// -------------Initialize---------------------------------------------

//--------------Disabled-----------------------------------------------
void disabled() {}
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
  baseControlTask_t = new pros::Task(baseControlTask);
  liftControlTask_t = new pros::Task(liftControlTask);

  intakeStates intakeState = intakeStates::driver;

  while(true)
  {
    if(HIDMain.get_digital(DIGITAL_LEFT))
    {
      autonSelector.run();
    }

    pros::delay(20);
  }
}
//------------opControl------------------------------------------------

void coutTask(void*)
{
  while(true)
  {
    std::cout <<"light_catapult"<<light_catapult.get_value_calibrated()<<std::endl;
    std::cout <<"m_catapult.getCurrentDraw = "<<m_catapult.getCurrentDraw()<<std::endl;
    std::cout <<"m_catapult Temperature" <<m_catapult.getTemperature()<<std::endl;
    pros::delay(20);
  }
}
