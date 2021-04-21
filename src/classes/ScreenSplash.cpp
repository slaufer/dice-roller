#include "../buildno.h"
#include "ProgramState.h"
#include "Screen.h"
#include "ScreenSplash.h"

void ScreenSplash::run(ProgramState &state) {
  char buf[17];
  snprintf(buf, 17, "Build #%d", BUILDNO);
  state.getDisplay().write(0, 0, "Electro-dice");
  state.getDisplay().write(1, 0, buf);
  state.getDisplay().draw();
  delay(2000);
  state.setScreen(SCREEN_MAIN_MENU);
}
