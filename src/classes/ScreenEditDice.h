#ifndef _CLASS_SCREENEDITDICE
#define _CLASS_SCREENEDITDICE

#include "DiceGroup.h"
#include "ProgramState.h"

class ScreenEditDice {
  public:
    bool mode = false;

  public:
    void run(ProgramState &state);
};

#endif
