#include "../config.h"
#include "ScreenRollBreakdown.h"
#include "ProgramState.h"

void ScreenRollBreakdown::run(ProgramState &state) {
  if (state.getButtonSel().getLongPressed()) {
    state.setScreen(SCREEN_MAIN_MENU);
    return;
  } else if (state.getButtonSel().getPressed()) {
    state.setScreen(SCREEN_ROLL_SUMMARY);
    return;
  } else if (state.getButtonPrev().getPressed() && this->pos > 0) {
    this->pos--;
  } else if (state.getButtonNext().getPressed() && this->pos < state.getRollCount() - 2) {
    this->pos++;
  }
 
  char buf[STRING_BUF_SIZE];

  state.getDisplay().write(0, 0, "");
  state.getDisplay().write(1, 0, "");

  for (int i = 0; i < state.getDisplay().getRows() && this->pos + i < state.getRollCount(); i++) {
    snprintf((char *) buf, STRING_BUF_SIZE, "%2d|d%d: %d", this->pos + i + 1, state.getRoll(this->pos+i).getType(), state.getRoll(this->pos+i).getRoll());
    state.getDisplay().write(i, 0, buf);
  }
}
