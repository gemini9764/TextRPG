#include "../Character/CombatStats.h"
#include "../System/Logger.h"
#include <algorithm>
#include <iostream>

CombatStats::CombatStats(int level, int hp, int atk, int experience) : level(level), hp(hp), maxhp(hp), attack(atk), experience(experience)
{}

void CombatStats::takeDamage(int amount)
{
    hp -= amount;
    hp = std::max(hp, 0);
    
    std::cout << amount << "의 데미지를 받았습니다(현재 체력 : " << hp << " / " << maxhp << ")" << std::endl;
}

void CombatStats::heal(int amount)
{
    hp += amount;
    hp = std::min(hp, maxhp);
    
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

void CombatStats::levelUp()
{
    if (level >= 10)
        return;

    while (experience >= 100)
    {
        if (level >= 10)
            break;

        level++;
        experience -= 100;
        maxhp += level * 20;
        attack += level * 5;
        hp = maxhp;

        std::cout << "레벨업!!" << std::endl;
    }
    std::cout << "최대 체력과 공격력이 상승했습니다!" << level << std::endl;
    std::cout << "체력이 모두 회복되었습니다!" << std::endl;
    Logger::getInstance().log("Level Up");
    
    showStats();
}
