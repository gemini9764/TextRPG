#pragma once
#include "Monster.h"

class Troll : public Monster
{
private:
    int hp;
    int atk;
    std::string name;
    
public:
    Troll(int level, bool isBoss = false)
    {
        hp = Utility::getRandomInRange(26, 28) * level;
        atk = Utility::getRandomInRange(8, 9) * level;
        name = "Troll";
        if (isBoss)
        {
            hp *= 1.5;
            atk *= 1.5;
            name += " Lord";
        }
    }
    std::string getName() const override { return name; }
    int getHp() const override { return hp; }
    int getAttack() const override { return atk; }
    void takeDamage(int amount) override { hp -= amount; if (hp < 0) hp = 0; }
    bool isDead() const override { return hp <= 0; }
};

