#include "ssd1306.h"

#include "../buildno.h"
#include "../aesop.h"
#include "ProgramState.h"
#include "Screen.h"
#include "ScreenSplash.h"

void ScreenSplash::run(ProgramState &state) {
  char buf[8];
  snprintf(buf, 8, "#%d", BUILDNO);
  /*
  state.getDisplay().write(0, 0, "Electro-dice");
  state.getDisplay().write(1, 0, buf);
  state.getDisplay().draw();
  */
  ssd1306_drawBitmap(0, 0, 128, 32, aesop);
  ssd1306_printFixed(96, 0, buf, STYLE_NORMAL);
  delay(2000);
  ssd1306_clearScreen();
  state.setScreen(SCREEN_MAIN_MENU);
}
