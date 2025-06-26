#include "CombatStats.h"
#include "../System/Logger.h"
#include "../System/Util.h"
#include "../System/Logger.h"
#include <algorithm>
#include <iostream>
#include <iomanip>

CombatStats::CombatStats(int level, int hp, int atk, int experience, int gold)
	: level(level), hp(hp), maxhp(hp),
	attack(atk), experience(experience), gold(gold)
{
	extraDamage = 0;
	membraneTurn = false;
	doubleTrun = false;
	dodge = false;
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
		std::cout << "회피 주사위를 굴립니다. 3이 나오면 공격을 회피합니다." << '\n';
		int missDice = Util::getRandomInRange(1, 6);
		
		std::cout << "주사위 눈이 " << missDice << "이(가) 나왔습니다. ";
		dodge = false;
		if (missDice == 3)
		{
			std::cout << "공격을 회피합니다!" << '\n';
			return;
		}
		else
		{
			std::cout << "회피에 실패합니다...." << '\n';
		}
	}

	hp -= amount;
	hp = std::max(hp, 0);

	std::cout << amount << "의 데미지를 받았습니다(현재 체력 : " << hp << " / " << maxhp << ")" << '\n';
}

void CombatStats::heal(int amount)
{
	hp += amount;
	hp = std::min(hp, maxhp);

	std::cout << "체력을 회복했습니다(현재 체력 : " << hp << " / " << maxhp << ")" << '\n';
}

void CombatStats::atkBoost(int amount)
{
	attack += amount;
	std::cout << "공격력이 " << amount << "만큼 상승했습니다." << '\n';
}

void CombatStats::hpBoost(int amount)
{
	maxhp += amount;
	std::cout << "최대 체력이 " << amount << "만큼 상승했습니다." << '\n';
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
	std::cout << "---------- 상태창 -----------" << '\n';
	std::cout << "레벨" << std::setw(10) << ": " << level << '\n';
	std::cout << "공격력" << std::setw(8) << ": " << attack << '\n';
	std::cout << "체력" << std::setw(10) << ": " << hp << '\n';
	std::cout << "최대 체력" << std::setw(5) << ": " << maxhp << '\n';
	std::cout << "경험치" << std::setw(8) << ": " << experience << '\n';
	std::cout << "골드" << std::setw(10) << ": " << gold << '\n';
	std::cout << "----------------------------" << '\n';
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

		std::cout << "레벨업!!" << '\n';
	}
	std::cout << "최대 체력과 공격력이 상승했습니다!" << '\n';
	std::cout << "체력이 모두 회복되었습니다!" << '\n';
	Logger::getInstance().log("Level Up");

	showStats();
}
