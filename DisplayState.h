#ifndef _DISPLAYSTATE_H
#define _DISPLAYSTATE_H

#include "CharState.h"

struct DisplayState {
  struct CharState* text = NULL;
  int count = 0;
  int rows = 0;
  int cols = 0;
  uint8_t fontWidth = 0;
  uint8_t fontHeight = 0;
};

#endif
