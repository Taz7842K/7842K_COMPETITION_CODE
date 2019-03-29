#pragma once
#include "main.h"

void catapultControlTask(void*);
void liftControlTask(void*);
void intakeControlTask(void*);
void baseControlTask(void*);

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
