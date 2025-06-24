#pragma once
#include "Item.h"
#include <memory>
#include <string>

class ItemFactory
{
public:
    static std::unique_ptr<Item> createItem(const std::string& id);
};
