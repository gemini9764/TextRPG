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
    Character(const std::string& name, int level, int hp, int atk, int experience);

    const std::string& getName() const;
    CombatStats& getStats();
    Inventory& getInventory();
};
