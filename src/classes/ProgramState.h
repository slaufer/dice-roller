#ifndef _CLASS_PROGRAMSTATE
#define _CLASS_PROGRAMSTATE

#include "../config.h"
#include "Button.h"
#include "TiltBall.h"
#include "Display.h"
#include "Screen.h"
#include "DiceProfile.h"
#include "Roll.h"

// a catch-all for managing program state between loops
class ProgramState {
  private:
    Display display;
    Button buttonSel;
    Button buttonPrev;
    Button buttonNext;
    TiltBall tiltBall;
    Screen screen = START_SCREEN;
    DiceProfile diceProfiles[DICE_PROFILES_MAX];
    int diceProfile = 0;
    int diceGroup = 0;
    Roll rolls[DICE_GROUPS_MAX * DICE_COUNT_MAX];
    int rollCount = 0;
    int rollSum = 0;

  public:
    void init();
    void update();

    Display &getDisplay();

    Button &getButtonSel();
    Button &getButtonPrev();
    Button &getButtonNext();

    TiltBall &getTiltBall();

    Screen getScreen();
    void setScreen(Screen screen);

    DiceProfile &getDiceProfile();
    DiceProfile &getDiceProfile(int i);
    void setDiceProfile(int diceProfile);

    DiceGroup &getDiceGroup();
    void setDiceGroup(int diceGroup);

    Roll &getRoll(int i);
    
    int getRollCount();
    void setRollCount(int rollSum);

    int getRollSum();
    void setRollSum(int rollSum);
};

#endif

