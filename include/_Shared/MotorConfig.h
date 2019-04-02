#pragma once

#include "main.h"

extern int8_t e_frontLeft;
extern int8_t e_frontRight;
extern int8_t e_rearLeft;
extern int8_t e_rearRight;

extern okapi::Motor m_frontLeft;
extern okapi::Motor m_frontRight;
extern okapi::Motor m_rearLeft;
extern okapi::Motor m_rearRight;

extern okapi::MotorGroup leftChassis;
extern okapi::MotorGroup rightChassis;

extern okapi::Motor m_intake;

extern okapi::Motor m_catapult;

extern okapi::Motor m_lift1;
extern okapi::Motor m_lift2;


extern okapi::ChassisControllerPID PIDxBase;

extern double pGain;
extern double dGain;
