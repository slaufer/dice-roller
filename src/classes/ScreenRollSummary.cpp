#include "ScreenRollSummary.h"
#include "ProgramState.h"
#include "Screen.h"

void ScreenRollSummary::run(ProgramState &state) {
  if (state.getButtonSel().getLongPressed()) {
    state.setScreen(SCREEN_MAIN_MENU);
    return;
  } else if (state.getButtonSel().getPressed()) {
    state.setScreen(SCREEN_ROLL_BREAKDOWN);
    return;
  }

  char buf[17];
  snprintf((char *) buf, 17, "%d", state.getRollSum());
  state.getDisplay().write(0, 0, "Roll total:");
  state.getDisplay().write(1, 0, buf);
};
