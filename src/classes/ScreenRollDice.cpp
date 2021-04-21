#include "Arduino.h"

#include "ScreenRollDice.h"
#include "ProgramState.h"

void ScreenRollDice::run(ProgramState &state) {
    int count = 0;
    int sum = 0;

    for (int i = 0; i < DICE_GROUPS_MAX; i++) {
      if (state.getDiceProfile().getDiceGroup(i).getType() == -1) {
        continue;
      }

      for (int j = 0; j < state.getDiceProfile().getDiceGroup(i).getCount(); j++) {
        int roll = random(1, state.getDiceProfile().getDiceGroup(i).getValue());
        sum += roll;

        if (state.getDiceProfile().getDiceGroup(i).getValue() == 1) {
          continue;
        }

        state.getRoll(count).setRoll(roll);
        state.getRoll(count).setType(state.getDiceProfile().getDiceGroup(i).getValue());
        count++;
      }
    }

    state.setRollCount(count);
    state.setRollSum(sum);
    state.setScreen(SCREEN_ROLL_SUMMARY);

    // a busy loop animation to make it look like something's happening
    char buf[4][17] = {
      "|-|-|-|-|-|-|-|-",
      "/\\/\\/\\/\\/\\/\\/\\/\\",
      "-|-|-|-|-|-|-|-|",
      "\\/\\/\\/\\/\\/\\/\\/\\/"
    };

    for (int i = 0; i < 8; i++) {
      state.getDisplay().write(0, 0, buf[i%4]);
      state.getDisplay().write(1, 0, buf[(i+2)%4]);
      state.getDisplay().draw();
      delay(75);
    }
}
