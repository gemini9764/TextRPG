#pragma once
#include <memory>
#include <string>
#include "Item.h"

class ItemFactory
{
public:
    static std::unique_ptr<Item> createItem(const std::string& id);
};
