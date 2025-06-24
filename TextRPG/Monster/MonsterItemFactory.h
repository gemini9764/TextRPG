#pragma once
#include "../Item/Item.h"
#include <memory>

class MonsterItemFactory
{
public:
    static std::unique_ptr<Item> createMonsterItem();
};
