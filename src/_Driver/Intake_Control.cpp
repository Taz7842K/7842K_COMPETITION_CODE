#include "main.h"
#include "7842K_Main.h"

intakeStates intakeState = intakeStates::driver;

void intakeControlTask(void*)
{
  while (true)
  {
    switch(intakeState)
    {
      case intakeStates::reverse:
      m_intake.move(127);
      break;

      case intakeStates::forward:
      m_intake.move(127);
      break;

      case intakeStates::stopped:
      m_intake.move(0);
      break;

      case intakeStates::driver:

      if(HIDMain.get_digital(DIGITAL_B))
      {
        m_intake.move(127);
      }

      else if(HIDMain.get_digital(DIGITAL_R1))
      {
        m_intake.move(-127);
      }

      else
      {
        m_intake.move(0);
      }

      break;
    }
  pros::delay(20);
  }
}
