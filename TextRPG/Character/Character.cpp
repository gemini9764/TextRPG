#include "../Character/Character.h"

Character::Character(const std::string& name, int level, int hp, int atk, int experience) : name(name), stats(level, hp, atk, experience) {}

const std::string& Character::getName() const { return name; }

CombatStats& Character::getStats() { return stats; }

Inventory& Character::getInventory() { return inventory; }