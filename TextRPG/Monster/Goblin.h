#pragma once
#include "Monster.h"

class Goblin : public Monster
{
private:
    int hp;
    int atk;
    std::string name;
    
public:
    Goblin(int level, bool isBoss = false)
    {
        hp = Util::getRandomInRange(22, 24) * level;
        atk = Util::getRandomInRange(6, 7) * level;
        name = "Goblin";
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
