#pragma once

#include "main.h"

extern okapi::Motor m_frontLeft;
extern okapi::Motor m_frontRight;
extern okapi::Motor m_rearLeft;
extern okapi::Motor m_rearRight;

extern okapi::MotorGroup leftChassis;
extern okapi::MotorGroup rightChassis;

extern okapi::Motor m_intake;

extern okapi::Motor m_catapult;

extern okapi::Motor m_lift;

extern okapi::ChassisControllerIntegrated skidBase;

extern double pGain;
extern double dGain;
