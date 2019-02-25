#pragma once

#include "main.h"
#include "_Auto/AutoConfig.h"
#include "_Shared/MotorConfig.h"
#include "_Shared/SensorConfig.h"
#include "_Driver/Base_Control.h"
#include "_Auto/driveArc.h"
#include "_Display/Auto_Selector.h"

void coutTask(void*);

void driverControlTask();
void baseControlTask();

extern float chassisWidth;

extern QLength QChassisWidth;

extern lib7842::AutonSelector autonSelector;
