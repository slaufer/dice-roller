#ifndef _CLASS_DICEPROFILE
#define _CLASS_DICEPROFILE

#include "DiceGroup.h"

class DiceProfile {
  private:
    DiceGroup diceGroups[DICE_GROUPS_MAX];

  public:
    DiceGroup &getDiceGroup(int i);
};

#endif
