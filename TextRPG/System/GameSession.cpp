﻿#include "GameSession.h"
#include <iostream>
#include <string>
#include "BattleManager.h"
#include "Logger.h"

GameSession::GameSession()
{
    initializeGame();
}

void GameSession::initializeGame()
{
    std::string name;
    
    while (true)
    {
		std::cout << "용사님의 이름을 입력해주세요 : " << std::flush;
        std::getline(std::cin, name);

        if (name.empty())
        {
            std::cout << "이름이 비어 있습니다. 다시 입력해주세요.\n>";
            
            continue;
        }

        if (name.find(' ') != std::string::npos)
        {
            std::cout << "이름에 공백이 포함되어 있습니다. 다시 입력해주세요.\n>";
            continue;
        }

        break; 
    }
    
    player = std::make_unique<Character>(name, 1, 200, 30, 0, 0);
    shop.restock();

    std::cout << "환영합니다 " << player->getName() << "님!" << '\n';
}

void GameSession::gameOver()
{
    std::cout << "게임을 재시작합니다" << '\n';
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 이전 입력의 개행문자를 제거해주는 것
    initializeGame();
}

void GameSession::gameClear()
{
    std::cout << "축하합니다! 게임을 클리어하셨습니다!" << '\n';
    exit(0);
}

void GameSession::visitShop()
{
    system("cls");

    while (true)
    {
        std::cout << "----------- 상점 -------------" << '\n';
        std::cout << "보유 Gold: " << player->getStats().getGold() << '\n';
        int action;
        std::cout << "1. 아이템 구매\n2. 아이템 판매\n0. 상점 나가기\n>";
        std::cin >> action;

		while (std::cin.fail() || (action != 1 && action != 2 && action != 0))
        {
            std::cout << "잘못된 입력입니다. 다시 선택해주세요.\n>";
            std::cin.clear();
            std::cin.ignore();
            std::cin >> action;
        }

        if (action == 0)
            return;

        if (action == 1)
        {
            shop.showItem();
            int buyChoice;
            std::cout << "구매할 물건을 선택하세요(0. 상점으로 되돌아가기)\n>";
            std::cin >> buyChoice;

			while (std::cin.fail() || (buyChoice < 0 || buyChoice > shop.getItemSize()))
            {
                std::cout << "잘못된 입력입니다. 다시 선택해주세요.\n>";
                std::cin.clear();
                std::cin.ignore();
                std::cin >> buyChoice;
            }

			if (buyChoice == 0)
				continue;
			else
			{
				if (shop.purchaseItem(buyChoice - 1, player->getStats()))
				{
					Item* item = shop.getItem(buyChoice - 1);

					if (item != nullptr)
					{
						player->getInventory().addItem(item->clone());
						std::cout << "구매가 완료되었습니다" << '\n';
					}
				}
				else
				{
					std::cout << "아이템 구매를 취소했습니다." << '\n';
				}
			}
        }
        else if (action == 2)
        {
            player->getInventory().showItems();

            if (player->getInventory().empty())
                continue;

            int sellChoice;
            std::cout << "판매할 물건을 선택하세요(0. 상점으로 되돌아가기)\n>";
            std::cin >> sellChoice;

			while (std::cin.fail() || (sellChoice < 0 || sellChoice > player->getInventory().size()))
            {
                std::cout << "잘못된 입력입니다. 다시 선택해주세요.\n>";
                std::cin.clear();
                std::cin.ignore();
                std::cin >> sellChoice;
            }

			if (sellChoice == 0)
				continue;

			Item* item = player->getInventory().getItem(sellChoice - 1);
			if (item != nullptr)
			{
				int sellPrice = static_cast<int>(item->getPrice() * 0.6);
				player->getStats().setGold(player->getStats().getGold() + sellPrice);
				shop.addItem(item->clone());

				std::cout << item->getName() << "을(를) " << sellPrice << "골드에 팔았습니다" << '\n';

				item->decreaseQuantity();
				if (item->getQuantity() <= 0)
				{
					player->getInventory().removeItem(sellChoice);
				}
			}
		}
    }
}

void GameSession::run()
{
    BattleManager battleManager;

    while (true)
    {
        std::cout << "1. 상점" << '\n';
        std::cout << "2. 상태창" << '\n';
        std::cout << "3. 전투" << '\n';
        std::cout << "4. 게임 종료" << '\n';

        int input;
        std::cin >> input;

        switch (input)
        {
        case 1:
            // 1. 상점
            visitShop();
            break;
        case 2:
            // 2. 상태창
            player->getStats().showStats();
            break;
        case 3:
            {
                BattleManager::BattleResult result = battleManager.startBattle(*player);
                if (result.playerWon)
                {
                    if (result.bossMonster)
                    {
                        Logger::getInstance().log("Game Exit");
                        gameClear();
                    }

                    player->getStats().setGold(player->getStats().getGold() + result.goldGained);
                    player->getStats().gainExp(result.expGained);
                    if (result.itemLooted != nullptr)
                    {
                        player->getInventory().addItem(result.itemLooted->clone());
                    }
                }
                else
                {
                    gameOver();
                }
                break;
            }
        case 4:
            // 4. 게임 종료
            std::cout << "게임을 종료합니다." << '\n';
            exit(0);
        default:
            std::cin.clear();
            std::cin.ignore();
            std::cout << "잘못된 입력입니다. 다시 선택해주세요.\n";
        }
    }
}
