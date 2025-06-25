#pragma once
#include <vector>
#include <memory>
#include "Item.h"

class ItemFactory
{
public:
    static std::vector<std::shared_ptr<Item>> createItem();
};
