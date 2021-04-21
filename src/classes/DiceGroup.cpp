#include "../config.h"
#include "DiceGroup.h"

int DiceGroup::getType() {
  return this->type;
}

void DiceGroup::setType(int type) {
  this->type = type;
}

int DiceGroup::getValue() {
  return DICE_TYPES[this->type];
}

int DiceGroup::getCount() {
  return this->count;
}

void DiceGroup::setCount(int count) {
  this->count = count;
}
