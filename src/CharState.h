#ifndef _CHARSTATE_H
#define _CHARSTATE_H

#include "ssd1306.h"

struct CharState {
  char ch;
  EFontStyle style;
  bool changed;
};

#endif
