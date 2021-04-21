#ifndef _CLASS_SCREENROLLBREAKDOWN
#define _CLASS_SCREENROLLBREAKDOWN

#include "ProgramState.h"

class ScreenRollBreakdown {
  private:
    int pos = 0;

  public:
    void run(ProgramState &state);
};

#endif
