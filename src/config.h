#ifndef _CONFIG_H
#define _CONFIG_H

#include "Arduino.h"

// button configs
#define BUTTON_COUNT 3
#define BUTTON_SEL_PIN 8
#define BUTTON_PREV_PIN 7
#define BUTTON_NEXT_PIN 9

#define BUTTON_STATE_DEFAULT HIGH
#define BUTTON_STATE_PRESSED LOW
#define BUTTON_PIN_MODE INPUT_PULLUP
#define LONG_PRESS_TIMEOUT 500

// tilt ball configs
#define TILT_BALL_PIN 3
#define TILT_BALL_PIN_MODE INPUT_PULLUP
#define TILT_BALL_SHAKE_FREQUENCY 200

// display configs
#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 32
#define DISPLAY_BUF_SIZE 84 /// 6x8 fits 21x4 characters, so 84
#define DISPLAY_FONT_DEFAULT ssd1306xled_font8x16

// screen configs
#define START_SCREEN SCREEN_SPLASH
#define STRING_BUF_SIZE 32 // size for various pre-display buffers

// dice configs
#define DICE_TYPE_COUNT 10
#define _DICE_TYPES { 1, 2, 4, 6, 8, 10, 12, 20, 30, 100 }
extern int DICE_TYPES[DICE_TYPE_COUNT];
#define DICE_TYPE_DEFAULT -1 // -1 is disabled/empty
#define DICE_COUNT_DEFAULT 1
#define DICE_COUNT_MAX 64
#define DICE_GROUPS_MAX 8
#define DICE_PROFILES_MAX 8
#define DICE_ROLL_BUFFER_SIZE DICE_GROUPS_MAX * DICE_COUNT_MAX
#define DICE_ROLL_SHAKE_DURATION 500

#endif
