#ifndef _CLASS_DISPLAY
#define _CLASS_DISPLAY

#include "ssd1306.h"

#include "../config.h"

class DisplayChar {
  public:
    char ch = ' ';
    EFontStyle style = STYLE_NORMAL;
    bool changed = true;
};

class Display {
  private:
    DisplayChar buf[DISPLAY_BUF_SIZE];
    int count = 0;
    int rows = 0;
    int cols = 0;

    uint8_t fontWidth;
    uint8_t fontHeight;

  public:
    void init();
    void setFont(const uint8_t *font);
    void write(int row, int col, char *text, EFontStyle style = STYLE_NORMAL, bool clearRow = true, bool wrap = false);
    void draw();

    int getRows();
    int getCols();
    uint8_t getFontWidth();
    uint8_t getFontHeight();
};

#endif
