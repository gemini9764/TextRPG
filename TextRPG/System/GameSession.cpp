#include "GameSession.h"
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
    std::cout << "    용사님의 이름을 입력해주세요 : ";
    std::cin >> name;
    player = std::make_unique<Character>(name, 1, 200, 30, 0, 0);
    shop.restock();

    std::cout << "환영합니다 " << player->getName() << "님!" << std::endl;
}

void GameSession::gameOver()
{
    std::cout << "게임을 재시작합니다" << std::endl;
    initializeGame();
}

void GameSession::gameClear()
{
    std::cout << "축하합니다! 게임을 클리어하셨습니다!" << std::endl;
    exit(0);
}

void GameSession::visitShop()
{
    system("cls");
    while (true)
    {
        std::cout << "----------- 상점 -------------" << std::endl;
        std::cout << "보유 Gold: " << player->getStats().getGold() << std::endl;
        int action;
        std::cout << "1. 아이템 구매\n2. 아이템 판매\n0. 상점 나가기\n>";
        std::cin >> action;

        if (action == 0)
            return;

        if (action == 1)
        {
            shop.showItem();
            int buyChoice;
            std::cout << "구매할 물건을 선택하세요(0. 상점으로 되돌아가기)\n>";
            std::cin >> buyChoice;

            if (buyChoice == 0)
                continue;

            if (shop.purchaseItem(buyChoice, player->getStats()))
            {
                Item* item = shop.getItem(buyChoice - 1);
                
                if (item != nullptr)
                {
                    player->getInventory().addItem(item->clone());
                    std::cout << "구매가 완료되었습니다" << std::endl;
                }
            }
            else
            {
                std::cout << "아이템 구매를 취소했습니다." << std::endl;
            }
        }
        else if (action == 2)
        {
            player->getInventory().showItems();
            int sellChoice;
            std::cout << "판매할 물건을 선택하세요(0. 상점으로 되돌아가기)\n>";
            std::cin >> sellChoice;

            if (sellChoice == 0)
                continue;

            Item* item = player->getInventory().getItem(sellChoice - 1);
            if (item != nullptr)
            {
                int sellPrice = static_cast<int>(item->getPrice() * 0.6);
                player->getStats().setGold(player->getStats().getGold() + sellPrice);
                shop.addItem(item->clone());

                std::cout << item->getName() << "을(를) " << sellPrice << "골드에 팔았습니다" << std::endl;

                item->decreaseQuantity();
                if (item->getQuantity() <= 0)
                {
                    player->getInventory().removeItem(sellChoice);
                }
            }
        }
        else
            std::cout << "다시 선택해주세요" << std::endl;
    }
}

void GameSession::run()
{
    BattleManager battleManager;

    while (true)
    {
        std::cout << "1. 상점" << std::endl;
        std::cout << "2. 상태창" << std::endl;
        std::cout << "3. 전투" << std::endl;
        std::cout << "4. 게임 종료" << std::endl;

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
                    player->getStats().setGold(player->getStats().getGold() + result.goldGained);
                    if (result.bossMonster)
                    {
                        Logger::getInstance().log("Game Exit");
                        gameClear();
                    }
                    
                    gold += result.goldGained;
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
            std::cout << "게임을 종료합니다." << std::endl;
            exit(0);
        default:
            std::cout << "다시 선택해주세요" << std::endl;
            system("cls");
        }
    }
}
