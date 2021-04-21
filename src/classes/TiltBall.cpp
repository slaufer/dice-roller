#include "Arduino.h"

#include "../config.h"
#include "TiltBall.h"

// this code is really sloppy and probably uses more variables than it needs to manage state
void TiltBall::update() {
  int newState = digitalRead(this->pin);
  unsigned long now = millis();

  // if the last update had the shaken flag, unset it now
  if (this->shaken) {
    this->shaken = false;
    this->shakeDuration = 0;
  }

  if (this->shaking) {
    // we are no longer shaking if the most recent change was more than TILT_BALL_SHAKE_FREQUENCY ms ago
    if (this->lastChange + TILT_BALL_SHAKE_FREQUENCY < now) {
      this->shaking = false;

      unsigned long shakeDuration = now - this->shakeStart;
      this->shaken = true;
      this->shakeDuration = shakeDuration;
    }
  } else {
    // we are shaking if:
    // - the state has changed
    // - the previous state change was less than TILT_BALL_SHAKE_FREQUENCY ms ago
    // this also has the effect of requiring at least two state changes to initiate a shake (at lastChange and now)
    if (newState != this->state &&  this->lastChange + TILT_BALL_SHAKE_FREQUENCY >= now) {
      this->shaking = true;
      this->shakeStart = this->lastChange;
    }
  }

  if (newState != this->state) {
    this->state = newState;
    this->lastChange = now;
  }
}

void TiltBall::setPin(int pin) {
  this->pin = pin;
  pinMode(this->pin, TILT_BALL_PIN_MODE);
  this->state = digitalRead(this->pin);
}

bool TiltBall::getShaken() {
  return this->shaken;
}

unsigned long TiltBall::getShakeDuration() {
  return this->shakeDuration;
}
