#pragma once

class CombatStats
{
private:
    int level;
    int hp;
    int maxhp;
    int attack;
    int experience;
    int extraDamage;
    bool membraneTurn;
    bool doubleTrun;
    bool dodge;
    
public:
    CombatStats(int level, int hp, int atk, int experience);

    void takeDamage(int amount);
    void heal(int amount);
    void atkBoost(int amount);
    void hpBoost(int amount);
    void levelUp();
    bool doubleAttack();
    
    void damage5() { membraneTurn = true; }
    void additionalDamage(int amount) { extraDamage = amount; }
    void doubleHit() { doubleTrun = true; }
    void dodgeDice() { dodge = true; }
    int getHp() const { return hp; }
    int getAttack() const { return attack; }
    bool isDead() const { return hp <= 0; }
    void showStats() const;
};
