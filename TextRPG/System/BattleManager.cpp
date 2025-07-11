﻿#include "BattleManager.h"
#include <iostream>
#include "../System/Util.h"
#include "../System/Logger.h"
#include "../Character/Character.h"
#include "../Monster/Monster.h"
#include "../Monster/MonsterFactory.h"

BattleManager::BattleResult BattleManager::startBattle(Character& player)
{
	std::unique_ptr<Monster> monster = MonsterFactory::CreateMonster(player.getStats().getLevel());
	std::cout << "전투를 시작합니다! 몬스터 : " << monster->getName() << '\n';
	Logger::getInstance().log("Battle started with " + monster->getName());

	while (!player.getStats().isDead() && !monster->isDead())
	{
		std::cout << player.getName() << "의 HP : " << player.getStats().getHp() << " / " << "Attack: " << player.getStats().getAttack() << '\n';
		std::cout << monster->getName() << "의 HP : " << monster->getHp() << " / " << "Attack: " << monster->getAttack() << '\n';

		std::cout << "1. 공격\n2. 아이템 사용\n>";
		int choice;
		std::cin >> choice;

		// 테스트용 즉시 사망
		if (choice == 9)
		{
			int maxHP = player.getStats().getHp();
			player.getStats().takeDamage(maxHP);
			break;
		}

		while (std::cin.fail() || (choice != 1 && choice != 2))
		{
			std::cout << "잘못된 입력입니다. 다시 선택해주세요.\n>";
			std::cin.clear();
			std::cin.ignore();
			std::cin >> choice;
		}

		if (choice == 1)
		{
			int playerDamage = player.getStats().getAttack();
			if (player.getStats().doubleAttack() == true)
			{
				playerDamage *= 2;
			}

			monster->takeDamage(playerDamage);
			std::cout << monster->getName() << "에게 " << playerDamage << "의 데미지를 주었습니다" << '\n';
		}
		else if (choice == 2)
		{
			if (player.getInventory().empty())
			{
				std::cout << "인벤토리가 비었습니다" << '\n';
				continue;
			}

			player.getInventory().showItems();
			std::cout << "아이템을 선택해주세요(0. 인벤토리 나가기)\n>";
			int itemIndex;
			std::cin >> itemIndex;

			while (std::cin.fail() || (itemIndex < 0 || itemIndex > player.getInventory().size()))
			{
				std::cout << "잘못된 입력입니다. 다시 선택해주세요.\n>";
				std::cin.clear();
				std::cin.ignore();
				std::cin >> itemIndex;
			}

			if (itemIndex == 0)
				continue;

			if (itemIndex >= 1 && itemIndex <= player.getInventory().size())
			{
				Item* item = player.getInventory().getItem(itemIndex - 1);
				item->use(player);
				player.getStats().showStats();

				if (item->isSoldOut())
				{
					player.getInventory().removeItem(itemIndex - 1);
				}
			}
		}

		if (monster->isDead())
			break;

		int monsterDamage = monster->getAttack();
		player.getStats().takeDamage(monsterDamage);
	}

	BattleResult result;
	result.bossMonster = monster->isBoss();
	if (player.getStats().isDead())
	{
		std::cout << "YOU DIED" << '\n';
		result.playerWon = false;
		result.goldGained = 0;
		result.expGained = 0;
		result.itemLooted = nullptr;
	}
	else
	{
		std::cout << "YOU WIN!!" << '\n';
		result.playerWon = true;

		if (result.bossMonster == true)
		{
			result.goldGained = 0;
			result.expGained = 0;
			result.itemLooted = nullptr;

			return result;
		}

		result.goldGained = Util::getRandomInRange(10, 20);
		result.expGained = 50;
		result.itemLooted = monster->dropLoot();

		if (result.itemLooted != nullptr)
		{
			std::cout << result.itemLooted->getName() << "을(를) 발견했습니다!" << '\n';
			Logger::getInstance().log("Get the Item(" + result.itemLooted->getName() + ")");
		}
		std::cout << "획득한 경험치 : " << result.expGained << " / 획득한 골드 : " << result.goldGained << '\n';
		Logger::getInstance().log("Get the exp(" + std::to_string(result.expGained) + ")");
		Logger::getInstance().log("Get the gold(" + std::to_string(result.goldGained) + ")");
	}

	return result;
}
