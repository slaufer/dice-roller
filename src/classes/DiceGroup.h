#ifndef _CLASS_DICEGROUP
#define _CLASS_DICEGROUP

#include "../config.h"

class DiceGroup {
  private:
    int type = DICE_TYPE_DEFAULT;
    int count  = DICE_COUNT_DEFAULT;

  public:
    int getType();
    void setType(int type);
    int getValue();

    int getCount();
    void setCount(int count);
};

#endif
