#include "ScreenEditDice.h"
#include "ProgramState.h"
#include "Screen.h"

void ScreenEditDice::run(ProgramState &state) {
  char buf[STRING_BUF_SIZE];

  // blank the unused part of the display
  if (state.getDisplay().getRows() > 2) {
    for (int i = 0; i < state.getDisplay().getRows(); i++) {
      state.getDisplay().write(i, 0, " ");
    }
  }

  if (this->mode) {
    // SETTING COUNT
    if (state.getButtonPrev().getLongPressed()) {
      state.getDiceGroup().setCount(state.getDiceGroup().getCount() - 10);
    } else if (state.getButtonPrev().getPressed()) {
      state.getDiceGroup().setCount(state.getDiceGroup().getCount() - 1);
    } else if (state.getButtonNext().getLongPressed()) {
      state.getDiceGroup().setCount(state.getDiceGroup().getCount() + 10);
    } else if (state.getButtonNext().getPressed()) {
      state.getDiceGroup().setCount(state.getDiceGroup().getCount() + 1);
    } else if (state.getButtonSel().getPressed()) {
      this->mode = false;
      state.setScreen(SCREEN_MAIN_MENU);
      return;
    }

    if (state.getDiceGroup().getCount() > DICE_COUNT_MAX) {
      state.getDiceGroup().setCount(DICE_COUNT_MAX);
    } else if (state.getDiceGroup().getCount() < 1) {
      state.getDiceGroup().setCount(1);
    }

    snprintf(buf, STRING_BUF_SIZE, "%d", state.getDiceGroup().getCount());
    state.getDisplay().write(0, 0, "Set dice count:");
    state.getDisplay().write(1, 0, buf);
  } else {
    // SETTING TYPE
    if (state.getButtonPrev().getPressed() && state.getDiceGroup().getType() > -1) {
      state.getDiceGroup().setType(state.getDiceGroup().getType() - 1);
    } else if (state.getButtonNext().getPressed() && state.getDiceGroup().getType() < DICE_TYPE_COUNT - 1) {
      state.getDiceGroup().setType(state.getDiceGroup().getType() + 1);
    } else if (state.getButtonSel().getPressed()) {
      this->mode = true;
      return;
    }

    state.getDisplay().write(0, 0, "Set dice type:");

    if (state.getDiceGroup().getType() == -1) {
      snprintf(buf, STRING_BUF_SIZE, "None");
    } else if (state.getDiceGroup().getValue() == 1) {
      snprintf(buf, STRING_BUF_SIZE, "Static Value");
    } else {
      snprintf(buf, STRING_BUF_SIZE, "d%d", state.getDiceGroup().getValue());
    }

    state.getDisplay().write(1, 0, buf);
  }
}
