#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include <memory>
#include <ostream>

#include "../System/Util.h"
#include "MonsterItemFactory.h"

class Item;

class Monster
{
protected:
    std::string monsterName;
    int hp;
    int atk;
    std::unique_ptr<Item> loogItem;
    
public:
    Monster(std::string name, int level, bool isBoss = false);
    virtual ~Monster() = default;

    std::string getName() const { return monsterName; }
    int getHp() const { return hp; }
    int getAttack() const { return atk; }
    bool isDead() const { return hp <= 0; }
    
    virtual void takeDamage(int amount)
    {
        hp -= amount;
        hp = std::max(hp, 0);
    }

    virtual void setLoot()
    {
        if (Util::getRandomInRange(1, 100) <= 30)
        {
            loogItem = MonsterItemFactory::createMonsterItem();
        }
    }
    virtual std::unique_ptr<Item> dropLoot() { return std::move(loogItem); }
};
