#pragma once
#include "Item.h"
#include "../System/Util.h"
#include <vector>
#include <memory>
#include <string>
#include "Item.h"

class ItemFactory
{
public:
    static std::vector<std::shared_ptr<Item>> createItem();
};
