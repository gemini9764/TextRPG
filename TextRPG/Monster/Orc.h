#pragma once
#include "Monster.h"

class Orc : public Monster
{
private:
    int hp;
    int atk;
    std::string name;
    
public:
    Orc(int level, bool isBoss = false)
    {
        hp = Util::getRandomInRange(24, 26) * level;
        atk = Util::getRandomInRange(7, 8) * level;
        name = "Orc";
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
