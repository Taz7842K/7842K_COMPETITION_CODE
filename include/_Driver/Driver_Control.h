#pragma once
#include "main.h"

void catapultControlTask(void*);
void liftControl();
void intakeControlTask(void*);
void baseControl();

enum class intakeStates
{

  forward,
  reverse,
  stopped,
  driver,

};
extern intakeStates intakeState;

enum class catapultStates
{
  loading,
  loaded,
  tare,
};
extern catapultStates catapultState;


enum class liftStates
{
  up,
  down,
  smoothstop,
  stopped,
};
extern liftStates liftState;
