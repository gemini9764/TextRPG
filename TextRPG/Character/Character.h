#pragma once
#include <string>
#include "CombatStats.h"
#include "Inventory.h"

class Character
{
private:
    std::string name;
    CombatStats stats;
    Inventory inventory;
    
public:
    Character(const std::string& name, int level, int hp, int atk, int experience, int gold)
        : name(name), stats(level, hp, atk, experience, gold) {}

    const std::string& getName() const { return name; }
    CombatStats& getStats() { return stats; }
    Inventory& getInventory() { return inventory; }
};
