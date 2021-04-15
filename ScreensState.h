#ifndef _SCREENSSTATE_H
#define _SCREENSSTATE_H

#include "DiceCountState.h"
#include "DiceTypeState.h"
#include "RollState.h"

struct ScreensState {
  struct DiceCountState diceCount;
  struct DiceTypeState diceType;
  struct RollState rollState;
};

#endif
