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

    int getHp() const { return hp; }
    int getAttack() const { return attack; }
    int getLevel() const { return level; }
    bool isDead() const { return hp <= 0; }
    void showStats() const;
};
