#ifndef _ROLLSTATE_H
#define _ROLLSTATE_H

#include "config.h"

struct RollState {
  int rolls[DICE_COUNT_MAX];
  int count;
};

#endif
