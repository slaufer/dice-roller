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
  setDisplayFont(display, digital_font5x7);
  //setDisplayFont(display, ssd1306xled_font5x7);
  //setDisplayFont(display, ssd1306xled_font6x8);
  //setDisplayFont(display, ssd1306xled_font8x16);
}

// sets the display font
// screen and text buffer will be cleared
void setDisplayFont(struct DisplayState *display, const uint8_t *font) {

  // first deallocate the existing text buffer if it exists
  if (display->lines != NULL) {
    for (int i = 0; i < display->rows; i++) {
      free(display->lines[i]);
    }
    
    free(display->lines);
  }

  if (display->linesChanged != NULL) {
    free(display->linesChanged);
  }

  // get font size (see ssd1306_fonts.c in lexus2k/ssd1306 for details)
  uint8_t fontWidth = font[1];
  uint8_t fontHeight = font[2];

  // figure out the new display size
  display->cols = DISPLAY_WIDTH / fontWidth;
  display->rows = DISPLAY_HEIGHT / fontHeight;
  display->lineHeight = fontHeight;

  // allocate the new text buffer
  display->lines = (char **) malloc(sizeof(char*) * display->rows);
  display->linesChanged = (bool*) malloc(sizeof(bool) * display->rows);
  for (int i = 0; i < display->rows; i++) {
    display->lines[i] = (char *) malloc(display->cols + 1);
    memset(display->lines[i], 0, display->cols + 1);
    display->linesChanged[i] = false;
  }

  // update the display library
  ssd1306_setFixedFont(font);
  ssd1306_clearScreen();

  char buf[17];
  snprintf((char*) buf, 17, "%dx%d  %dx%d", fontWidth, fontHeight, display->cols, display->rows);
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
    ssd1306_printFixed(0, display->lineHeight * i, display->lines[i], STYLE_BOLD);
  }
}