#ifndef _PROGRAMSTATE_H
#define _PROGRAMSTATE_H

#include "DisplayState.h"
#include "ButtonState.h"
#include "ScreensState.h"

enum Screen { SCREEN_SPLASH, SCREEN_SPLASH_HOLD, SCREEN_DICE_COUNT, SCREEN_DICE_TYPE, SCREEN_ROLL, SCREEN_ROLL_DISPLAY };
#define START_SCREEN SCREEN_SPLASH

struct ProgramState {
  struct DisplayState display;
  struct ButtonState buttons[BUTTON_COUNT];
  struct ScreensState screens;
  Screen screen = START_SCREEN;
};

#endif
