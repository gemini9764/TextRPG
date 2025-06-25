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
        std::cout << "ȸ�� �ֻ����� �����ϴ�. 3�� ������ ������ ȸ���մϴ�." << std::endl;
        int missDice = Util::getRandomInRange(1, 6);

        if (missDice == 3)
        {
            std::cout << "�ֻ��� ���� 3�� ���Խ��ϴ�! ������ ȸ���մϴ�!" << std::endl;
            return;
        }
    }

    hp -= amount;
    hp = std::max(hp, 0);

    std::cout << amount << "�� �������� �޾ҽ��ϴ�(���� ü�� : " << hp << " / " << maxhp << ")" << std::endl;
}

void CombatStats::heal(int amount)
{
    hp += amount;
    hp = std::min(hp, maxhp);

    std::cout << "ü���� ȸ���߽��ϴ�(���� ü�� : " << hp << " / " << maxhp << ")" << std::endl;
}

void CombatStats::atkBoost(int amount)
{
    attack += amount;
    std::cout << "���ݷ��� " << amount << "��ŭ ����߽��ϴ�." << std::endl;
}

void CombatStats::hpBoost(int amount)
{
    maxhp += amount;
    std::cout << "�ִ� ü���� " << amount << "��ŭ ����߽��ϴ�." << std::endl;
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
    std::cout << "---------- ����â -----------" << std::endl;
    std::cout << "����      : " << level << std::endl;
    std::cout << "���ݷ�    : " << attack << std::endl;
    std::cout << "ü��      : " << hp << " / " << maxhp << std::endl;
    std::cout << "����ġ    : " << experience << std::endl;
    std::cout << "���      : " << gold << std::endl;
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

        std::cout << "������!!" << std::endl;
    }
    std::cout << "최대 체력과 공격력이 상승했습니다!" << std::endl;
    std::cout << "체력이 모두 회복되었습니다!" << std::endl;
    Logger::getInstance().log("Level Up");

    showStats();
}
