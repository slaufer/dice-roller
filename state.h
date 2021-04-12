#ifndef _STATE_H
#define _STATE_H

#include "config.h"

#define SCREEN_DICE_COUNT 0
#define SCREEN_DICE_TYPE 1

#define START_SCREEN SCREEN_DICE_COUNT

struct ButtonState {
   int state = BUTTON_STATE_DEFAULT;
   bool pressed = false;
   bool longPressed = false;
   unsigned long lastChange = millis();
};

struct DisplayState {
  char **lines  = NULL;
  bool *linesChanged = NULL;
  int rows = 0;
  int cols = 0;
  int lineHeight = 0;
};

struct DiceCountState {
  int count = defaultDiceCount;
};

struct DiceTypeState {
  int type = defaultDiceType;
};

struct ScreensState {
  struct DiceCountState diceCount;
  struct DiceTypeState diceType;
};

struct ProgramState {
  struct DisplayState display;
  struct ButtonState buttons[BUTTON_COUNT];
  struct ScreensState screens;
  int screen = START_SCREEN;
};

#endif