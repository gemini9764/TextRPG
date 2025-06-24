#pragma once
#include <memory>
#include <string>
#include "Effect.h"

class Character;

class Item
{
private:
    std::string name;
    int price;
    int quantity;
    std::unique_ptr<Effect> effect;
    
public:
    Item(const std::string& name, int price, int quantity, std::unique_ptr<Effect> eff);
    void use(Character& target);
    const std::string& getName() const;
    int getPrice() const;
    int getQuantity() const;
    void decreaseQuantity();
    void increaseQuantity();
    bool isSoldOut() const;

    std::unique_ptr<Item> clone() const;
};
