#pragma once
#include <string>

class Monster
{
public:    
    virtual ~Monster() = default;
    virtual std::string getName() const = 0;
    virtual int getHp() const = 0;
    virtual int getAttack() const = 0;
    virtual void takeDamage(int amount) = 0;
    virtual bool isDead() const = 0;
};
