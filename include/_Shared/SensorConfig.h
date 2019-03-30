#pragma once

#include "main.h"

extern okapi::Potentiometer pot_catapult;

extern okapi::ADIEncoder enc_catapult;

extern pros::ADIAnalogIn light_catapult;

extern pros::ADIDigitalIn sw_catapult;

extern pros::Controller HIDMain;

extern double initPotCatapult;

double pot_catapultRead();
