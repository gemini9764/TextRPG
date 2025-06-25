#pragma once

/**
 * @class CombatStats
 * @brief 전투와 관련된 캐릭터의 스탯 정보를 관리하는 클래스.
 *
 * CombatStats 클래스는 캐릭터의 레벨, 체력, 공격력, 경험치, 골드와 같은
 * 기본 스탯을 관리하며, 여러 전투 행위와 상호작용을 제공합니다.
 */
class CombatStats
{
private:
    int level;
    int hp;
    int maxhp;
    int attack;
    int experience;
    int gold;
    int extraDamage;
    bool membraneTurn;
    bool doubleTrun;
    bool dodge;

public:
    CombatStats(int level, int hp, int atk, int experience, int gold);

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
    int getGold() const { return gold; }
    bool isDead() const { return hp <= 0; }
    void showStats() const;

    void setGold(int value);
    void gainExp(int expUp)
    {
        experience += expUp;
        if (experience >= 100)
            levelUp();
    }
};
