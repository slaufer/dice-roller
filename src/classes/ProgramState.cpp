#include "../config.h"
#include "ProgramState.h"
#include "Button.h"
#include "Display.h"

// initialize sensors and display
void ProgramState::init() {
  // initialize buttons
  this->buttonSel.setPin(BUTTON_SEL_PIN);
  this->buttonPrev.setPin(BUTTON_PREV_PIN);
  this->buttonNext.setPin(BUTTON_NEXT_PIN);

  this->tiltBall.setPin(TILT_BALL_PIN);

  // initialize display
  this->getDisplay().init();
}

// update sensors and redraw display
void ProgramState::update() {
  this->display.draw();

  this->buttonSel.update();
  this->buttonPrev.update();
  this->buttonNext.update();

  this->tiltBall.update();
}

Display &ProgramState::getDisplay() {
  return this->display;
}

Button &ProgramState::getButtonSel() {
  return this->buttonSel;
}

Button &ProgramState::getButtonPrev() {
  return this->buttonPrev;
}

Button &ProgramState::getButtonNext() {
  return this->buttonNext;
}

TiltBall &ProgramState::getTiltBall() {
  return this->tiltBall;
}

Screen ProgramState::getScreen() {
  return this->screen;
}

void ProgramState::setScreen(Screen screen) {
  this->screen = screen;
}

// gets the active dice profile
DiceProfile &ProgramState::getDiceProfile() {
  return this->getDiceProfile(this->diceProfile);
}

// gets a specified dice profile
DiceProfile &ProgramState::getDiceProfile(int i) {
  return this->diceProfiles[i];
}

// sets the active dice profile
void ProgramState::setDiceProfile(int diceProfile) {
  this->diceProfile = diceProfile;
}

// gets the active dice group
DiceGroup &ProgramState::getDiceGroup() {
  return this->getDiceProfile().getDiceGroup(this->diceGroup);
}

// sets the active dice group
void ProgramState::setDiceGroup(int diceGroup) {
  this->diceGroup = diceGroup;
}

Roll &ProgramState::getRoll(int i) {
  return this->rolls[i];
}

int ProgramState::getRollCount() {
  return this->rollCount;
}

void ProgramState::setRollCount(int rollCount) {
  this->rollCount = rollCount;
}

int ProgramState::getRollSum() {
  return this->rollSum;
}

void ProgramState::setRollSum(int rollSum) {
  this->rollSum = rollSum;
}
