#pragma once

#include "main.h"
#include "_Auto/AutoConfig.h"
#include "_Shared/MotorConfig.h"
#include "_Shared/SensorConfig.h"
#include "_Driver/Base_Control.h"

void coutTask(void*);

void driverControlTask();
void baseControlTask();
