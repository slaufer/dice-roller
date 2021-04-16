#include "ssd1306.h"

#include "Display.h"

void Display::init() {
  ssd1306_128x32_i2c_init();
  this->setFont(ssd1306xled_font8x16);
}

void Display::setFont(const uint8_t *font) {
  // get font size (see ssd1306_fonts.c in lexus2k/ssd1306 for details)
  uint8_t fontWidth = font[1];
  uint8_t fontHeight = font[2];

  // figure out the new display size
  this->cols = DISPLAY_WIDTH / fontWidth;
  this->rows = DISPLAY_HEIGHT / fontHeight;
  this->count = this->rows * this->cols;
  this->fontWidth = fontWidth;
  this->fontHeight = fontHeight;

  // clear the buffer
  for (int i = 0; i < this->count; i++) {
    this->buf[i].ch = ' ';
    this->buf[i].style = STYLE_NORMAL;
    this->buf[i].changed = true;
  }

  // update the display library
  ssd1306_setFixedFont(font);
  ssd1306_clearScreen();
}

void Display::write(int row, int col, char *text, EFontStyle style, bool clearRow, bool wrap) {
  int i = 0;
  int off = row * this->cols + col;

  // keep reading until we run out of input or screen space, or hit the end of the row if wrap is false
  int stop = this->count;
  if (!wrap) {
    stop = (row + 1) * this->cols;
  }

  for (i = 0; text[i] != 0 && off+i < stop; i++) {
    // only flag the character changed if it is different
    if (this->buf[off+i].ch != text[i] || this->buf[off+i].style != style) {
      this->buf[off+i].ch = text[i];
      this->buf[off+i].style = style;
      this->buf[off+i].changed = true;
    }
  }

  // clear the rows surrounding the text if clearRow = true
  if (clearRow) {
    int j;

    // clear before
    for (j = row * this->cols; j < this->count && j < off; j++) {
      if (this->buf[j].ch != ' ') {
        this->buf[j].ch = ' ';
        this->buf[j].style = STYLE_NORMAL;
        this->buf[j].changed = true;
      }
    }

    int nextRow = ((off + i - 1) / this->cols + 1) * this->cols;

    // clear after
    for (j = off + i; j < this->count && j < nextRow; j++) {
      this->buf[j].ch = ' ';
      this->buf[j].style = STYLE_NORMAL;
      this->buf[j].changed = true;
    }
  }
}

void Display::draw() {
  char buf[2] = { 0, 0 };
  int i;
  int x;
  int y;

  for (int row = 0; row < this->rows; row++) {
    for (int col = 0; col < this->cols; col++) {
      i = row * this->cols + col;

      if (!this->buf[i].changed) {
        continue;
      }

      this->buf[i].changed = false;
      x = col * this->fontWidth;
      y = row * this->fontHeight;
      
      buf[0] = this->buf[i].ch;
      ssd1306_printFixed(x, y, buf, this->buf[i].style);
    }
  }
}

int Display::getRows() {
  return this->rows;
}

int Display::getCols() {
  return this->cols;
}

uint8_t Display::getFontWidth() {
  return this->fontWidth;
}

uint8_t Display::getFontHeight() {
  return this->fontHeight;
}


