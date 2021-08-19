#include "ssd1306.h"

#include "../config.h"
#include "Program.h"
#include "Screen.h"

#include "FlashAsEEPROM.h"

void Program::setup() {
  this->state.init();
  randomSeed(analogRead(0) + micros());
}

void Program::loop() {
  this->state.update();

  char buf[17];

  // check the tilt ball to see if we should initiate a roll
  if (this->state.getTiltBall().getShaken() && this->state.getTiltBall().getShakeDuration() > DICE_ROLL_SHAKE_DURATION) {
    this->state.setScreen(SCREEN_ROLL_DICE);
  }

  // i could probably create a unified interface for all of the screens, but since we're doing static allocation for
  // everything it's kind of pointless
  if (this->state.getScreen() == SCREEN_SPLASH) {
    this->screenSplash.run(this->state);
  } else if (this->state.getScreen() == SCREEN_MAIN_MENU) {
    this->screenMainMenu.run(this->state);
  } else if (this->state.getScreen() == SCREEN_EDIT_DICE) {
    this->screenEditDice.run(this->state);
  } else if (this->state.getScreen() == SCREEN_PROFILE_MENU) {
    this->screenProfileMenu.run(this->state);
  } else if (this->state.getScreen() == SCREEN_ROLL_DICE) {
    this->screenRollDice.run(this->state);
  } else if (this->state.getScreen() == SCREEN_ROLL_SUMMARY) {
    this->screenRollSummary.run(this->state);
  } else if (this->state.getScreen() == SCREEN_ROLL_BREAKDOWN) {
    this->screenRollBreakdown.run(this->state);
  }

  delay(1);
}

