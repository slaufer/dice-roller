#ifndef _CLASS_PROGRAM
#define _CLASS_PROGRAM

#include "ProgramState.h"
#include "ScreenSplash.h"
#include "ScreenMainMenu.h"
#include "ScreenEditDice.h"
#include "ScreenProfileMenu.h"
#include "ScreenRollDice.h"
#include "ScreenRollSummary.h"
#include "ScreenRollBreakdown.h"

class Program {
  private:
    ProgramState state;

    ScreenSplash screenSplash;
    ScreenMainMenu screenMainMenu;
    ScreenEditDice screenEditDice;
    ScreenProfileMenu screenProfileMenu;
    ScreenRollDice screenRollDice;
    ScreenRollSummary screenRollSummary;
    ScreenRollBreakdown screenRollBreakdown;

  public:
    void setup();
    void loop();
};

#endif
