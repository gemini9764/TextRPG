#pragma once
#include "Monster.h"

class Slime : public Monster
{
private:
    int hp;
    int atk;
    std::string name;
    
public:
    Slime(int level, bool isBoss = false)
    {
        hp = Util::getRandomInRange(20, 22) * level;
        atk = Util::getRandomInRange(5, 6) * level;
        name = "Slime";
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
