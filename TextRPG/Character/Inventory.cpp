#include "Inventory.h"
#include <iostream>

void Inventory::addItem(std::unique_ptr<Item> newItem)
{
    if (newItem == nullptr)
        return;

    for (std::unique_ptr<Item>& item : inven)
    {
        if (item->getName() == newItem->getName())
        {
            item->increaseQuantity();
            return;
        }
    }
    
    inven.push_back(std::move(newItem));
}

void Inventory::showItems() const
{
    std::cout << "--------- 인벤토리 ----------" << std::endl;
    for (int i = 0; i < inven.size(); i++)
    {
        std::cout << i + 1 << ". " << inven[i]->getName() << " (수량: " << inven[i]->getQuantity() << std::endl;
    }
}

Item* Inventory::getItem(int index) const
{
    if (index < 1 || index > inven.size())
        return nullptr;
    return inven[index - 1].get();
}

void Inventory::removeItem(int index)
{
    if (index < 1 || index > inven.size())
        return;
    inven.erase(inven.begin() + (index - 1));
}