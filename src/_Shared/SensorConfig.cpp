#include "main.h"
#include "_Shared/SensorConfig.h"

okapi::Potentiometer pot_catapult('C');

pros::ADIDigitalIn sw_catapult('E');

pros::Controller HIDMain(CONTROLLER_MASTER);
