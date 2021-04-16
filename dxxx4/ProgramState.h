#ifndef _PROGRAMSTATE_H
#define _PROGRAMSTATE_H

#include "config.h"

#include "DisplayState.h"
#include "ButtonState.h"
#include "ScreensState.h"
#include "Screen.h"


struct ProgramState {
  struct DisplayState display;
  struct ButtonState buttons[BUTTON_COUNT];
  struct ScreensState screens;
  Screen screen = START_SCREEN;
};

#endif
