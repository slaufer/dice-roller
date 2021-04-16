#ifndef _CLASS_PROGRAM
#define _CLASS_PROGRAM

#include "../config.h"
#include "Button.h"
#include "Display.h"

class Program {
  private:
    Button buttons[BUTTON_COUNT];
    Display display;

  public:
    void setup();
    void loop();

    Button prevButton();
    Button selButton();
    Button nextButton();
};

#endif
