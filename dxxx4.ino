#include <string.h>
#include "Arduino.h"
#include "ssd1306.h"

#include "config.h"
#include "state.h"
#include "buttons.h"
#include "display.h"

// using globals because i'm a big stupid baby
struct ProgramState state;

/////////////
// SCREENS //
/////////////

void splashScreen() {
  writeDisplay(state.display, 0, 0, "electro-dice 0.1", STYLE_BOLD);
  writeDisplay(state.display, 1, 0, "die human scum");
  drawDisplay(state.display);
  delay(2000);

  state.screen = SCREEN_DICE_COUNT;
}

void diceCountScreen() {
  char buf[17];

  if (state.buttons[BUTTON_PREV].longPressed) {
    state.screens.diceCount.count -= 10;
  } else if (state.buttons[BUTTON_PREV].pressed) {
    state.screens.diceCount.count--;
  } else if (state.buttons[BUTTON_NEXT].longPressed) {
    state.screens.diceCount.count += 10;
  } else if (state.buttons[BUTTON_NEXT].pressed) {
    state.screens.diceCount.count++;
  } else if (state.buttons[BUTTON_SEL].pressed) {
    state.screen = SCREEN_DICE_TYPE;
  }

  if (state.screens.diceCount.count < 1) {
    state.screens.diceCount.count = 1;
  }
  
  writeDisplay(state.display, 0, 0, "Dice Count:");
  snprintf((char *) buf, 17, "%d", state.screens.diceCount.count);
  writeDisplay(state.display, 1, 0, buf, STYLE_BOLD);
}

void diceTypeScreen() {
  char buf[17];

  if (state.buttons[BUTTON_PREV].pressed && state.screens.diceType.type > 0) {
    state.screens.diceType.type--;
  } else if (state.buttons[BUTTON_NEXT].pressed && state.screens.diceType.type < (diceTypeCount - 1)) {
    state.screens.diceType.type++;
  } else if (state.buttons[BUTTON_SEL].pressed) {
    state.screen = SCREEN_ROLL;
  }
  
  writeDisplay(state.display, 0, 0, "Dice Type:");
  int countLen = snprintf((char *) buf, 17, "%d", state.screens.diceCount.count);
  writeDisplay(state.display, 1, 0, buf, STYLE_NORMAL);
  snprintf((char *) buf, 17, "d%d", diceTypes[state.screens.diceType.type]);
  writeDisplay(state.display, 1, countLen, buf, STYLE_BOLD, false);
}

void rollScreen() {
  if (state.screens.rollState.rolls != NULL) {
    free(state.screens.rollState.rolls);
  }

  state.screens.rollState.rolls = (int*) malloc(sizeof(int) * state.screens.diceCount.count);
  state.screens.rollState.count = state.screens.diceCount.count;

  for (int i = 0; i < state.screens.diceCount.count; i++) {
    state.screens.rollState.rolls[i] = random(1, diceTypes[state.screens.diceType.type] + 1);
  }

  state.screen = SCREEN_ROLL_DISPLAY;
}

void rollDisplayScreen() {
  if (state.buttons[BUTTON_SEL].pressed) {
    state.screen = SCREEN_DICE_COUNT;
  }

  int sum = 0;

  for (int i = 0; i < state.screens.rollState.count; i++) {
    sum += state.screens.rollState.rolls[i];
  }

  char buf[17];
  snprintf((char*) buf, 17, "roll sum: %d", sum);
  writeDisplay(state.display, 0, 1, buf);
}

//////////
// MAIN //
//////////

void setup()
{
    Serial.begin(9600);

    pinMode(3, INPUT_PULLUP);

    // initialize button pins
    for (int i = 0; i < BUTTON_COUNT; i++) {
      pinMode(BUTTON_PINS[i], BUTTON_PIN_MODE);
    }
    
    // initialize display
    initDisplay(state.display);

    // initialize rng
    // TODO: better random seeding
    randomSeed(analogRead(0) + micros());
}

void loop()
{
  updateButtonStates(state.buttons);

  switch (state.screen) {
    case SCREEN_SPLASH:
      splashScreen();
    case SCREEN_DICE_COUNT:
      diceCountScreen();
      break;
    case SCREEN_DICE_TYPE:
      diceTypeScreen();
      break;
    case SCREEN_ROLL:
      rollScreen();
      break;
    case SCREEN_ROLL_DISPLAY:
      rollDisplayScreen();
      break;
  }

  drawDisplay(state.display);
}
