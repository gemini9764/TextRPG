#pragma once

class CombatStats
{
private:
    int level;
    int hp;
    int maxhp;
    int attack;
    int experience;
    
public:
    CombatStats(int level, int hp, int atk, int experience);

    void takeDamage(int amount);
    void heal(int amount);

    int getHp() const;
    int getAttack() const;
    bool isDead() const;
    void showStats() const;
};
