#include <string.h>

#include "Arduino.h"
#include "display.h"
#include "config.h"
#include "state.h"
#include "ssd1306.h"

/////////////
// DISPLAY //
/////////////

// TODO: everything about this display code sucks

// initializes the display
void initDisplay(struct DisplayState *display) {
  ssd1306_128x32_i2c_init();
  setDisplayFont(display, ssd1306xled_font8x16, 2, 16, 16);
}

// sets the display font
// screen and text buffer will be cleared
void setDisplayFont(struct DisplayState *display, const uint8_t *font) {
  // get font size (see ssd1306_fonts.c in lexus2k/ssd1306 for details)
  uint8_t fontWidth = font[1];
  uint8_t fontHeight = font[2];

  ssd1306_setFixedFont(font);
  ssd1306_clearScreen();

  // DEALLOCATION
  if (display->lines != NULL) {
    for (int i = 0; i < display->rows; i++) {
      free(display->lines[i]);
    }
    
    free(display->lines);
  }

  if (display->linesChanged != NULL) {
    free(display->linesChanged);
  }

  // REALLOCATION
  display->lines = (char **) malloc(sizeof(char*) * rows);
  display->linesChanged = (bool*) malloc(sizeof(bool) * rows);
  for (int i = 0; i < rows; i++) {
    display->lines[i] = (char *) malloc(cols + 1);
    memset(display->lines[i], 0, cols + 1);
    display->linesChanged[i] = false;
  }

  display->rows = rows;
  display->cols = cols;
  display->lineHeight = lineHeight;

  char buf[17];
  snprintf((char*) buf, 17, "%dx%d", fontWidth, fontHeight);
  writeDisplay(display, 0, buf);
}

// updates the display text buffer
void writeDisplay(struct DisplayState *display, int line, char* text) {
  if (strcmp(display->lines[line], text) == 0) {
    return;
  }
    
  strncpy(display->lines[line], text, display->cols);
  display->linesChanged[line] = true;
}

// draws the display if the text buffer has been updated
void drawDisplay(struct DisplayState *display) {
  bool doUpdate = false;

  for (int i = 0; i < display->rows; i++) {
    if (display->linesChanged[i]) {
      doUpdate = true;
      display->linesChanged[i] = false;
    }
  }

  if (!doUpdate) {
    return;
  }

  // TODO: only redraw the updated line
  ssd1306_clearScreen();
  for (int i = 0; i < display->rows; i++) {
    ssd1306_printFixed(0, display->lineHeight * i, display->lines[i], STYLE_NORMAL);
  }
}