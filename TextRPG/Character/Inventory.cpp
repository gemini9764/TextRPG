﻿#include "Inventory.h"
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
    std::cout << "--------- 인벤토리 ----------" << '\n';

    if (!inven.empty())
    {
        for (int i = 0; i < inven.size(); i++)
        {
            std::cout << i + 1 << ". " << inven[i]->getName() << " (수량: " << inven[i]->getQuantity() << ")" << '\n';
        }
    }
    else
    {
        std::cout << "현재 인벤토리가 비어있습니다.\n";
    }
}

Item* Inventory::getItem(int index) const
{
    if (index < 0 || index > inven.size())
        return nullptr;
    return inven[index].get();
}

void Inventory::removeItem(int index)
{
    if (index < 0 || index > inven.size())
        return;
    inven.erase(inven.begin() + index);
}
