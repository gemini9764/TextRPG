#include "CombatStats.h"
#include "../System/Logger.h"
#include "../System/Util.h"
#include "../System/Logger.h"
#include <algorithm>
#include <iostream>
#include "../System/Logger.h"

CombatStats::CombatStats(int level, int hp, int atk, int experience, int gold)
    : level(level), hp(hp), maxhp(hp),
      attack(atk), experience(experience), gold(gold)
{
}

void CombatStats::takeDamage(int amount)
{
    if (membraneTurn == true)
    {
        amount = 5;
        membraneTurn = false;
    }
    else if (dodge == true)
    {
        std::cout << "회피 주사위를 굴립니다. 3이 나오면 공격을 회피합니다." << std::endl;
        int missDice = Util::getRandomInRange(1, 6);

        if (missDice == 3)
        {
            std::cout << "주사위 눈이 3이 나왔습니다! 공격을 회피합니다!" << std::endl;
            return;
        }
    }

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

void CombatStats::atkBoost(int amount)
{
    attack += amount;
    std::cout << "공격력이 " << amount << "만큼 상승했습니다." << std::endl;
}

void CombatStats::hpBoost(int amount)
{
    maxhp += amount;
    std::cout << "최대 체력이 " << amount << "만큼 상승했습니다." << std::endl;
}

bool CombatStats::doubleAttack()
{
    if (doubleTrun == true)
    {
        doubleTrun = false;
        return true;
    }

    return false;
}

void CombatStats::showStats() const
{
    std::cout << "---------- 상태창 -----------" << std::endl;
    std::cout << "레벨      : " << level << std::endl;
    std::cout << "공격력    : " << attack << std::endl;
    std::cout << "체력      : " << hp << " / " << maxhp << std::endl;
    std::cout << "경험치    : " << experience << std::endl;
    std::cout << "골드      : " << gold << std::endl;
    std::cout << "----------------------------" << std::endl;
}

void CombatStats::setGold(int value)
{
    gold = value;
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
