#include "../buildno.h"
#include "Program.h"

void Program::setup() {
  Serial.begin(9600);

  // initialize buttons
  for (int i = 0; i < BUTTON_COUNT; i++) {
    this->buttons[i].setPin(BUTTON_PINS[i]);
  }

  // initialize display
  // TODO: don't use config macros in Display
  this->display.init();

  // initialize rng
  // TODO: better random seeding
  randomSeed(analogRead(0) + micros());

  char buf[17];
  snprintf(buf, 17, "Build #%d", BUILDNO);

  this->display.write(0, 0, "Electro-dice");
  this->display.write(1, 0, buf);
  delay(1000);
}

void Program::loop() {
  // update buttons
  for (int i = 0; i < BUTTON_COUNT; i++) {
    this->buttons[i].update();
  }

  char buf[17];

  for (int i = 0; i < BUTTON_COUNT; i++) {
    if (this->buttons[i].getLongPressed()) {
      snprintf((char *) buf, 17, "%d long pressed", i);
      this->display.write(0, 0, buf);
    } else if (this->buttons[i].getPressed()) {
      snprintf((char *) buf, 17, "%d pressed", i);
      this->display.write(0, 0, buf);
    }
  }

  this->display.draw();
  delay(5);
}

// ------------------------------------ //

Button Program::prevButton() {
  return this->buttons[BUTTON_PREV];
}

Button Program::selButton() {
  return this->buttons[BUTTON_SEL];
}

Button Program::nextButton() {
  return this->buttons[BUTTON_NEXT];
}
