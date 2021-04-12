#ifndef _CONFIG_H
#define _CONFIG_H

#include "Arduino.h"

// button configs
#define BUTTON_COUNT 3
#define _BUTTON_PINS { 7, 8, 9 }
extern int BUTTON_PINS[BUTTON_COUNT]; // defined in config.cpp

#define BUTTON_PREV 0
#define BUTTON_SEL 1
#define BUTTON_NEXT 2

#define BUTTON_STATE_DEFAULT HIGH
#define BUTTON_STATE_PRESSED LOW
#define BUTTON_PIN_MODE INPUT_PULLUP

#define LONG_PRESS_TIMEOUT 500

// display configs
#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 32

// dice configs
#define defaultDiceCount 1
#define diceTypeCount 9
#define _DICE_TYPES { 2, 4, 6, 8, 10, 12, 20, 30, 100 }
extern int diceTypes[diceTypeCount]; // defined in config.cpp
#define defaultDiceType 6

#endif