#ifndef _CLASS_SCREENROLLSUMMARY
#define _CLASS_SCREENROLLSUMMARY

#include "ProgramState.h"

class ScreenRollSummary {
  private:
    int mode = 0;

  public:
    void run(ProgramState &state);
};

#endif
