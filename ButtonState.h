#ifndef _BUTTONSTATE_H
#define _BUTTONSTATE_H

#include "Arduino.h"

struct ButtonState {
   int state = BUTTON_STATE_DEFAULT;
   bool pressed = false;
   bool longPressed = false;
   unsigned long lastChange = millis();
};

#endif
