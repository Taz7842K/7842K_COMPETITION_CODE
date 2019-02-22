#pragma once

#include "main.h"

extern int e_frontLeft;
extern int e_frontRight;
extern int e_rearLeft;
extern int e_rearRight;

extern okapi::MotorGroup leftChassis;
extern okapi::MotorGroup rightChassis;

extern okapi::Motor m_intake;

extern okapi::Motor m_catapult;

extern okapi::Motor m_lift;

extern okapi::ChassisControllerPID skidBase;
