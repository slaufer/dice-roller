#ifndef _CLASS_SCREENPROFILEMENU
#define _CLASS_SCREENPROFILEMENU

#include "ProgramState.h"
#include "DiceProfile.h"

class ScreenProfileMenu {
  private:
    int selected = 0;
    void profileToString(char *buf, int bufSize, DiceProfile &profile);

  public:
    void run (ProgramState &state);
};

#endif
