#include "CombatStats.h"
#include <iostream>

CombatStats::CombatStats(int level, int hp, int atk, int experience) : level(level), hp(hp), maxhp(hp), attack(atk), experience(experience)
{}

void CombatStats::takeDamage(int amount)
{
    hp -= amount;
    if (hp < 0)
        hp = 0;
    std::cout << amount << "의 데미지를 받았습니다(현재 체력 : " << hp << " / " << maxhp << ")" << std::endl;
}

void CombatStats::heal(int amount)
{
    hp += amount;
    if (hp > maxhp)
        hp = maxhp;
    std::cout << "체력을 회복했습니다(현재 체력 : " << hp << " / " << maxhp << ")" << std::endl;
}

void CombatStats::showStats() const
{
    std::cout << "---------- 상태창 -----------" << std::endl;
    std::cout << "레벨      : " << level << std::endl;
    std::cout << "공격력    : " << attack << std::endl;
    std::cout << "체력      : " << hp << std::endl;
    std::cout << "최대 체력 : " << maxhp << std::endl;
    std::cout << "경험치    : " << experience << std::endl;
    std::cout << "----------------------------" << std::endl;
}


int CombatStats::getHp() const { return hp; }
int CombatStats::getAttack() const { return attack; }
bool CombatStats::isDead() const { return hp <= 0; }