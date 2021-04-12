#ifndef _DISPLAY_H

#include "state.h"

extern void initDisplay(struct DisplayState *display);
extern void setDisplayFont(struct DisplayState *display, const uint8_t *font, int rows, int cols, int lineHeight);
extern void writeDisplay(struct DisplayState *display, int line, char* text);
extern void drawDisplay(struct DisplayState *display);

#define _DISPLAY_H
#endif