#pragma once
#include <vector>
#include <memory>

class Item;

class Shop
{
private:
    std::vector<std::shared_ptr<Item>> items;
    
public:
    void initialize();
    void addItem(std::unique_ptr<Item> newItem);
    void showItem() const;
    Item* getItem(int index) const;
    bool purchasItem(int index, int& playerMoney);
    void restock();
};