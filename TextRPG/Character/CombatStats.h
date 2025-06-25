#pragma once

/**
 * @class CombatStats
 * @brief 전투 관련 능력치를 관리하는 클래스.
 *        체력, 공격력, 레벨, 경험치 등의 데이터를 포함하고,
 *        데미지 처리, 치유, 레벨업, 경험치 증가 등을 처리하는 기능을 제공한다.
 */
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
    int getLevel() const { return level; }
    bool isDead() const { return hp <= 0; }
    void showStats() const;
    void gainExp(int expUp)
    {
        experience += expUp;
        if (experience >= 100)
            levelUp();
    }
};
