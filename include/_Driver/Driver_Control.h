#pragma once
#include "main.h"

void catapultControlTask(void*);
void liftControlTask(void*);
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
  trigger,
};
extern catapultStates catapultState;


enum class liftStates
{
  tinyLift,
  driver,
  stopped,
  unfold,
  placeCap,
  holdCap,
};
extern liftStates liftState;
