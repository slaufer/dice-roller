#include <string.h>
#include "Arduino.h"
#include "ssd1306.h"

#include "display.h"
#include "DisplayState.h"
#include "config.h"

/////////////
// DISPLAY //
/////////////

// initializes the display
void initDisplay(struct DisplayState &display) {
  ssd1306_128x32_i2c_init();
  //setDisplayFont(display, digital_font5x7);
  //setDisplayFont(display, ssd1306xled_font5x7);
  //setDisplayFont(display, ssd1306xled_font6x8);
  setDisplayFont(display, ssd1306xled_font8x16);
}

// sets the display font
// screen and text buffer will be cleared
void setDisplayFont(struct DisplayState &display, const uint8_t *font) {
  if (display.text != NULL) {
    free(display.text);
  }

  // get font size (see ssd1306_fonts.c in lexus2k/ssd1306 for details)
  uint8_t fontWidth = font[1];
  uint8_t fontHeight = font[2];

  // figure out the new display size
  display.cols = DISPLAY_WIDTH / fontWidth;
  display.rows = DISPLAY_HEIGHT / fontHeight;
  display.count = display.rows * display.cols;
  display.fontWidth = fontWidth;
  display.fontHeight = fontHeight;

  // allocate the new text buffer
  display.text = (struct CharState*) malloc(display.count * sizeof(struct CharState));

  for (int i = 0; i < display.count; i++) {
    display.text[i].ch = ' ';
    display.text[i].style = STYLE_NORMAL;
    display.text[i].changed = true;
  }

  // update the display library
  ssd1306_setFixedFont(font);
  ssd1306_clearScreen();
}

// updates the display text buffer
void writeDisplay(struct DisplayState &display, int row, int col, char *text, EFontStyle style, bool clearRow, bool wrap) {
  int i = 0;
  int off = row * display.cols + col;

  // keep reading until we run out of input or screen space, or hit the end of the row if wrap is false
  int stop = display.count;
  if (!wrap) {
    stop = (row + 1) * display.cols;
  }

  for (i = 0; text[i] != 0 && off+i < stop; i++) {
    // only flag the character changed if it is different
    if (display.text[off+i].ch != text[i] || display.text[off+i].style != style) {
      display.text[off+i].ch = text[i];
      display.text[off+i].style = style;
      display.text[off+i].changed = true;
    }
  }

  // clear the rows surrounding the text if clearRow = true
  if (clearRow) {
    int j;

    // clear before
    for (j = row * display.cols; j < display.count && j < off; j++) {
      if (display.text[j].ch != ' ') {
        display.text[j].ch = ' ';
        display.text[j].style = STYLE_NORMAL;
        display.text[j].changed = true;
      }
    }

    int nextRow = ((off + i - 1) / display.cols + 1) * display.cols;

    // clear after
    for (j = off + i; j < display.count && j < nextRow; j++) {
      display.text[j].ch = ' ';
      display.text[j].style = STYLE_NORMAL;
      display.text[j].changed = true;
    }
  }
}

// draws the display if the text buffer has been updated
void drawDisplay(struct DisplayState &display) {
  char buf[2] = { 0, 0 };
  int i;
  int x;
  int y;

  for (int row = 0; row < display.rows; row++) {
    for (int col = 0; col < display.cols; col++) {
      i = row * display.cols + col;

      if (!display.text[i].changed) {
        continue;
      }

      display.text[i].changed = false;
      x = col * display.fontWidth;
      y = row * display.fontHeight;
      
      buf[0] = display.text[i].ch;
      ssd1306_printFixed(x, y, buf, display.text[i].style);
    }
  }
}
