#ifndef _CLASS_BUTTON
#define _CLASS_BUTTON

#include "Arduino.h"
#include "../config.h"

class Button {
  private:
    int pin = -1;
    int state = BUTTON_STATE_DEFAULT;
    unsigned long lastChange = millis();
    bool pressed = false;
    bool longPressed = false;

  public:
    void update();
    void setPin(int pin);
    bool getPressed();
    bool getLongPressed();
    bool getDown();
};

#endif
