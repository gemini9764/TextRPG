#pragma once
#include "../Item/Item.h"
#include <vector>
#include <memory>
#include <iostream>

class Inventory
{
private:
    std::vector<std::unique_ptr<Item>> inven;
    
public:
    void addItem(std::unique_ptr<Item> newItem);
    void showItems() const;
    Item* getItem(int index) const;
    void removeItem(int index);
};
