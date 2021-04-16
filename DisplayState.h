#ifndef _DISPLAYSTATE_H
#define _DISPLAYSTATE_H

#include "config.h"
#include "CharState.h"

struct DisplayState {
  // malloc is a lot of work, we'll just guess the max size and define it in config.h
  struct CharState text[DISPLAY_BUF_SIZE];
  int count = 0;
  int rows = 0;
  int cols = 0;
  uint8_t fontWidth = 0;
  uint8_t fontHeight = 0;
};

#endif
