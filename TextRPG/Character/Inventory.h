#pragma once
#include <vector>
#include <memory>
#include "../Item/Item.h"

class Inventory
{
private:
    std::vector<std::unique_ptr<Item>> inven;
    
public:
    void addItem(std::unique_ptr<Item> newItem);
    void showItems() const;
    Item* getItem(int index) const;
    void removeItem(int index);
    bool empty() const { return inven.empty(); }
    size_t size() const { return inven.size(); }
};
