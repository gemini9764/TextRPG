#pragma once
#include <string>
#include "../Character/CombatStats.h"
#include "../Character/Inventory.h"

class Character
{
private:
    std::string name;
    CombatStats stats;
    Inventory inventory;
    
public:
    Character(const std::string& name, int level, int hp, int atk, int experience)
        : name(name), stats(level, hp, atk, experience) {}

    const std::string& getName() const { return name; }
    CombatStats& getStats() { return stats; }
    Inventory& getInventory() { return inventory; }
};
