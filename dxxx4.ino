#include "config.h"
#include "state.h"
#include "buttons.h"
#include "display.h"

// using globals because i'm a big stupid baby
struct ProgramState state;

/////////////
// SCREENS //
/////////////

void diceCountScreen() {
  char buf[17];

  if (state.buttons[BUTTON_PREV].pressed && state.screens.diceCount.count > 1) {
    state.screens.diceCount.count--;
  } else if (state.buttons[BUTTON_NEXT].pressed) {
    state.screens.diceCount.count++;
  } else if (state.buttons[BUTTON_SEL].pressed) {
    state.screen = SCREEN_DICE_TYPE;
  }
  
  writeDisplay(&(state.display), 0, "Dice Count:");
  snprintf((char *) buf, 17, "%d", state.screens.diceCount.count);
  writeDisplay(&(state.display), 1, buf);
}

void diceTypeScreen() {
  char buf[17];

  if (state.buttons[BUTTON_PREV].pressed && state.screens.diceType.type > 0) {
    state.screens.diceType.type--;
  } else if (state.buttons[BUTTON_NEXT].pressed && state.screens.diceType.type < (diceTypeCount - 1)) {
    state.screens.diceType.type++;
  } else if (state.buttons[BUTTON_SEL].pressed) {
    0;
  }
  
  writeDisplay(&(state.display), 0, "Dice Type:");
  snprintf((char *) buf, 17, "d%d", diceTypes[state.screens.diceType.type]);
  writeDisplay(&(state.display), 1, buf);
}

//////////
// MAIN //
//////////

void setup()
{
    Serial.begin(9600);

    // initialize button pins
    for (int i = 0; i < BUTTON_COUNT; i++) {
      pinMode(BUTTON_PINS[i], BUTTON_PIN_MODE);
    }
    
    // initialize display
    initDisplay(&(state.display));

    // initialize rng
    // TODO: better random seeding
    randomSeed(analogRead(0) + micros());
}

void loop()
{
  updateButtonStates(state.buttons);

/*
  switch (state.screen) {
    case SCREEN_DICE_COUNT:
      diceCountScreen();
      break;
    case SCREEN_DICE_TYPE:
      diceTypeScreen();
      break;
  }
*/
  
  drawDisplay(&(state.display));
  delay(5);
}
