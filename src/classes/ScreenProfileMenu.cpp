#include "ScreenProfileMenu.h"
#include "ProgramState.h"
#include "Screen.h"
#include "DiceProfile.h"

void ScreenProfileMenu::profileToString(char *buf, int bufSize, DiceProfile &profile) {
  int sp = 0;
 
  for (int i = 0; i < DICE_GROUPS_MAX && bufSize - sp > 0; i++) {
    if (profile.getDiceGroup(i).getType() == -1) {
      continue;
    }

    if (profile.getDiceGroup(i).getValue() == 1) {
      sp += snprintf(
        buf + sp, bufSize - sp, "%d+",
        profile.getDiceGroup(i).getCount()
      );
    } else {
      sp += snprintf(
        buf + sp, bufSize - sp, "%dd%d+",
        profile.getDiceGroup(i).getCount(),
        profile.getDiceGroup(i).getValue()
      );
    }

  }

  // deal with empty sets and trailing join characters
  if (sp == 0) {
    snprintf(buf, bufSize, "Empty");
  } else if (sp <= bufSize && buf[sp-1] == '+') {
    buf[sp-1] = 0;
  }
};

// TODO: updates to reduce calls to snprintf()
void ScreenProfileMenu::run(ProgramState &state) {
  int optionCount = DICE_PROFILES_MAX;
  int start;
  
if (state.getButtonPrev().getPressed() && this->selected > 0) {
    this->selected--;
  } else if (state.getButtonNext().getPressed() && this->selected < optionCount - 1) {
    this->selected++;
  } else if (state.getButtonSel().getPressed()) {
    state.setDiceProfile(this->selected);
    state.setScreen(SCREEN_MAIN_MENU);
  }

  if (optionCount <= state.getDisplay().getRows()) {
    start = 0;
  } else if (this->selected > optionCount - state.getDisplay().getRows()) {
    start = optionCount - state.getDisplay().getRows();
  } else {
    start = this->selected;
  }

  char buf[STRING_BUF_SIZE];

  for (int i = 0; i < state.getDisplay().getRows(); i++) {
    snprintf((char *) buf, STRING_BUF_SIZE, "%s%2d|", start + i == this-> selected ? ">" : " ", start + i + 1, start + i + 1);
    this->profileToString(buf + 4, STRING_BUF_SIZE - 4, state.getDiceProfile(start+i));

    state.getDisplay().write(i, 0, buf);
  }
}
