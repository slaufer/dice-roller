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
// 6x8 fits 21x4 characters, so 84 + some fluff so i don't have to manually reboot after it segfaults
#define DISPLAY_BUF_SIZE 128

// screen configs
#define START_SCREEN SCREEN_SPLASH

// dice configs
#define DICE_COUNT_MAX 128
#define DEFAULT_DICE_COUNT 1
#define DICE_TYPE_COUNT 10
#define _DICE_TYPES { 1, 2, 4, 6, 8, 10, 12, 20, 30, 100 }
extern int DICE_TYPES[DICE_TYPE_COUNT]; // defined in config.cpp
#define DEFAULT_DICE_TYPE 7

#endif
