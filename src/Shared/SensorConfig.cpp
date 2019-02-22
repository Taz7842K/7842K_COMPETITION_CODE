#include "main.h"
#include "_Shared/SensorConfig.h"

okapi::Potentiometer pot_armLift('A');
okapi::Potentiometer pot_capFlipper('B');
okapi::Potentiometer pot_catapult('C');

pros::ADILineSensor light_capDetect('C');

pros::Controller HIDMain(CONTROLLER_MASTER);
