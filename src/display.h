#ifndef _DISPLAY_H

#include "DisplayState.h"
#include "ssd1306.h"

// display functions to minimize draws and hopefully reduce flicker
extern void initDisplay(struct DisplayState &display);
extern void setDisplayFont(struct DisplayState &display, const uint8_t *font);
extern void writeDisplay(struct DisplayState &display, int row, int col, char *text, EFontStyle style = STYLE_NORMAL, bool clearRow = true, bool wrap = false);
extern void drawDisplay(struct DisplayState &display);

#define _DISPLAY_H
#endif
