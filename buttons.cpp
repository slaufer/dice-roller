#include "config.h"
#include "ButtonState.h"

// updates all of the button states, press/long press detection, etc.
void updateButtonStates(struct ButtonState buttons[])
{
  unsigned long now = millis();
  
  for (int i = 0; i < BUTTON_COUNT; i++)
  {
    int newState = digitalRead(BUTTON_PINS[i]);

    if (buttons[i].state != newState) {
      if (newState == BUTTON_STATE_DEFAULT) {
        buttons[i].pressed = true;

        if (now - buttons[i].lastChange > LONG_PRESS_TIMEOUT) {
          buttons[i].longPressed = true;
        }
      }
      
      buttons[i].state = newState;
      buttons[i].lastChange = now;
    } else {
      buttons[i].pressed = false;
      buttons[i].longPressed = false;
    }
  }
}
