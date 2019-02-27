#pragma once

#include "main.h"
#include "_Auto/AutoConfig.h"
#include "_Shared/MotorConfig.h"
#include "_Shared/SensorConfig.h"
#include "_Driver/Base_Control.h"
#include "_Auto/Auto_Drive_Functions.h"
#include "_Display/Auto_Selector.h"
#include "_Driver/Driver_Control.h"


void coutTask(void*);
void killTask(void*);

void driverControlTask();
void intakeControlTask();
void baseControlTask();

extern float chassisWidth;

extern QLength QChassisWidth;

extern lib7842::AutonSelector autonSelector;
