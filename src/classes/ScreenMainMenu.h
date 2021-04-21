#ifndef _CLASS_SCREENMAINMENU
#define _CLASS_SCREENMAINMENU

#include "../config.h"
#include "ProgramState.h"

class ScreenMainMenu {
  private:
    int selected = 0;
  public:
    void run(ProgramState &state);
};

#endif
