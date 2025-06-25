#pragma once
#include <algorithm>
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
    int atk;
    std::unique_ptr<Item> loogItem;
    
public:
    Monster(std::string name, int level, bool isBoss = false, float healthMultiply = 1.f, float attakMultiply = 1.f);
    virtual ~Monster() = default;

    std::string getName() const { return name; }
    int getHp() const { return hp; }
    int getAttack() const { return atk; }
    bool isDead() const { return hp <= 0; }
    
    virtual void takeDamage(int amount)
    {
        hp -= amount;
        hp = std::max(hp, 0);
    }

    void setLoot(std::unique_ptr<Item> item)
    {
        if (Util::getRandomInRange(1, 100) <= 30)
            loogItem = MonsterItemFactory::createMonsterItem();
    }
    std::unique_ptr<Item> dropLoot() { return std::move(loogItem); }
};
