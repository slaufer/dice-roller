#include "Arduino.h"

#include "../config.h"
#include "Button.h"

void Button::update() {
  int newState = digitalRead(this->pin);

  if (this->state == newState) {
    this->pressed = false;
    this->longPressed = false;
    return;
  }
  
  unsigned long now = millis();

  if (newState == BUTTON_STATE_DEFAULT) {

    if (this->lastChange + LONG_PRESS_TIMEOUT < now) {
      this->longPressed = true;
    }

    this->pressed = true;
  }

  this->lastChange = now;
  this->state = newState;
}

void Button::setPin(int pin) {
  pinMode(pin, BUTTON_PIN_MODE);
  this->pin = pin;
}

bool Button::getPressed() {
  return this->pressed;
}

bool Button::getLongPressed() {
  return this->longPressed;
}
