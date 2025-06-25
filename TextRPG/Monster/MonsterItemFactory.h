#pragma once
#include <memory>
#include "../Item/Item.h"

class MonsterItemFactory
{
public:
    static std::unique_ptr<Item> createMonsterItem();
};
