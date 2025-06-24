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
    void levelUp();

    int getHp() const { return hp; }
    int getAttack() const { return attack; }
    int getLevel() const { return level; }
    bool isDead() const { return hp <= 0; }
    void showStats() const;
    void gainExp(int expUp)
    {
        this->experience += expUp;
        if (this->experience >= 100)
            this->levelUp();
    }
};
