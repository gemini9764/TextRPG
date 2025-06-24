#pragma once
#include "Monster.h"

class Dragon : public Monster
{
private:
    int hp;
    int atk;
    std::string name;
    
public:
    Dragon(int level, bool isBoss = false)
    {
        hp = Util::getRandomInRange(28, 30) * level;
        atk = Util::getRandomInRange(9, 10) * level;
        name = "Dragon";
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
