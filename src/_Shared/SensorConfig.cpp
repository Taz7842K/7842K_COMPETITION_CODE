#include "main.h"
#include "_Shared/SensorConfig.h"

okapi::Potentiometer pot_catapult('C');

okapi::ADIEncoder enc_catapult('G','H');

pros::ADIAnalogIn light_catapult('E');

pros::ADIDigitalIn sw_catapult('A');

pros::Controller HIDMain(CONTROLLER_MASTER);

double initPotCatapult;

double pot_catapultRead()
{

  double pot_catapultRead = pot_catapult.get() - initPotCatapult;

  return pot_catapultRead;
}
