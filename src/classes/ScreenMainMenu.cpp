#include "../config.h"
#include "ProgramState.h"
#include "ScreenMainMenu.h"
#include "Screen.h"

// the menu looks like this:
// >Choose Profile...
//  1. <dice group 0>
//  2. <dice group 1>
// ...
// TODO: updates to reduce calls to snprintf()
void ScreenMainMenu::run(ProgramState &state) {
  int optionCount = DICE_GROUPS_MAX + 1;
  int start;

  if (state.getButtonPrev().getPressed() && this->selected > 0) {
    this->selected--;
  } else if (state.getButtonNext().getPressed() && this->selected < optionCount - 1) {
    this->selected++;
  } else if (state.getButtonSel().getPressed()) {
    if (this->selected == 0) {
      state.setScreen(SCREEN_PROFILE_MENU);
    } else {
      state.setDiceGroup(this->selected - 1);
      state.setScreen(SCREEN_EDIT_DICE);
    }

    return;
  }

  // TODO: we don't need to update the display every time
  if (optionCount <= state.getDisplay().getRows()) {
    start = 0;
  } else if (this->selected > optionCount - state.getDisplay().getRows()) {
    start = optionCount - state.getDisplay().getRows();
  } else {
    start = this->selected;
  }

  char buf[STRING_BUF_SIZE];

  for (int i = 0; i < state.getDisplay().getRows(); i++) {
    if (start + i == 0) {
      snprintf((char *) buf, STRING_BUF_SIZE, "%s  |Profile...", start + i == this->selected ? ">" : " ");
    } else if (state.getDiceProfile().getDiceGroup(start+i-1).getType() == -1) {
      snprintf((char *) buf, STRING_BUF_SIZE, "%s%2d|Empty", start + i == this-> selected ? ">" : " ", start + i);
    } else if (state.getDiceProfile().getDiceGroup(start+i-1).getValue() == 1) {
      snprintf((char *) buf, STRING_BUF_SIZE, "%s%2d|%d", start + i == this->selected ? ">" : " ", start + i, state.getDiceProfile().getDiceGroup(start+i-1).getCount());
    } else {
      snprintf((char *) buf, STRING_BUF_SIZE, "%s%2d|%dd%d", start + i == this->selected ? ">" : " ", start + i, state.getDiceProfile().getDiceGroup(start+i-1).getCount(), state.getDiceProfile().getDiceGroup(start+i-1).getValue());
    }

    state.getDisplay().write(i, 0, buf);
  }
}
