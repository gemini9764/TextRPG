#pragma once
#include <string>
#include <memory>
#include "../System/Util.h"
#include "MonsterItemFactory.h"

class Item;

class Monster
{
protected:
    std::string name;
    int hp;
    int attack;
    std::unique_ptr<Item> loogItem;
    
public:    
    virtual ~Monster() = default;
    virtual std::string getName() const = 0;
    virtual int getHp() const = 0;
    virtual int getAttack() const = 0;
    virtual void takeDamage(int amount) = 0;
    virtual bool isDead() const = 0;

    void setLoot(std::unique_ptr<Item> item)
    {
        if (Util::getRandomInRange(1, 100) <= 30)
            loogItem = MonsterItemFactory::createMonsterItem();
    }
    std::unique_ptr<Item> dropLoot() { return std::move(loogItem); }
};
