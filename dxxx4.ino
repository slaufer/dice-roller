#include <string.h>
#include "src/classes/Program.h"

/////////////
// SCREENS //
/////////////

/*

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
  } else if (state.screens.diceCount.count > DICE_COUNT_MAX) {
    state.screens.diceCount.count = DICE_COUNT_MAX;
  }
  
  writeDisplay(state.display, 0, 0, "Dice Count:");
  snprintf((char *) buf, 17, "%d", state.screens.diceCount.count);
  writeDisplay(state.display, 1, 0, buf, STYLE_BOLD);
}

void diceTypeScreen() {
  char buf[17];

  if (state.buttons[BUTTON_PREV].pressed && state.screens.diceType.type > 0) {
    state.screens.diceType.type--;
  } else if (state.buttons[BUTTON_NEXT].pressed && state.screens.diceType.type < (DICE_TYPE_COUNT - 1)) {
    state.screens.diceType.type++;
  } else if (state.buttons[BUTTON_SEL].pressed) {
    state.screen = SCREEN_ROLL;
  }
  
  writeDisplay(state.display, 0, 0, "Dice Type:");
  int countLen = snprintf((char *) buf, 17, "%d", state.screens.diceCount.count);
  writeDisplay(state.display, 1, 0, buf, STYLE_NORMAL);
  snprintf((char *) buf, 17, "d%d", DICE_TYPES[state.screens.diceType.type]);
  writeDisplay(state.display, 1, countLen, buf, STYLE_BOLD, false);
}

void rollScreen() {
  state.screens.rollState.count = state.screens.diceCount.count;

  for (int i = 0; i < state.screens.diceCount.count; i++) {
    state.screens.rollState.rolls[i] = random(1, DICE_TYPES[state.screens.diceType.type] + 1);
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

*/

//////////
// MAIN //
//////////

Program program;

void setup()
{
  program.setup();
}

Button b;

void loop()
{
  program.loop();
}