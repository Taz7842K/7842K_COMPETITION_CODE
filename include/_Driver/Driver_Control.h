#pragma once
#include "main.h"

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
