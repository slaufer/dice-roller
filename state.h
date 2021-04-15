#ifndef _STATE_H
#define _STATE_H

#include "ssd1306.h"

#include "config.h"
#include "DisplayState.h"
#include "ButtonState.h"

enum Screen { SCREEN_SPLASH, SCREEN_SPLASH_HOLD, SCREEN_DICE_COUNT, SCREEN_DICE_TYPE, SCREEN_ROLL, SCREEN_ROLL_DISPLAY };

#define START_SCREEN SCREEN_SPLASH

struct DiceCountState {
  int count = defaultDiceCount;
};

struct DiceTypeState {
  int type = defaultDiceType;
};

struct RollState {
  int* rolls = NULL;
  int count;
};

struct ScreensState {
  struct DiceCountState diceCount;
  struct DiceTypeState diceType;
  struct RollState rollState;
};

struct ProgramState {
  struct DisplayState display;
  struct ButtonState buttons[BUTTON_COUNT];
  struct ScreensState screens;
  Screen screen = START_SCREEN;
};

#endif
