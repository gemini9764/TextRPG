#include "GameSession.h"
#include <iostream>
#include <limits>

GameSession::GameSession(const std::string& name) : playerName(name), gold(100)
{
    initializeGame();
}

void GameSession::initializeGame()
{
    player = std::make_unique<Character>(playerName, 1, 200, 30, 0);
    shop.restock();
    gold = 100;

    std::cout << "환영합니다 " << playerName << "님!" << std::endl;
}

void GameSession::gameOver()
{
    std::cout << "You died" << std::endl;
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

            if (shop.purchasItem(buyChoice, gold))
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
                std::cout << "아이템 구매에 실패하였습니다." << std::endl;
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
                int sellPrice = item->getPrice() * 0.6;
                gold += sellPrice;
                shop.addItem(item->clone());
                
                std::cout << item->getName() << "을(를) " << sellPrice << "골드에 팔았습니다" << std::endl;
                
                item->decreaseQuantity();
                if (item->getQuantity() < 0)
                {
                    player->getInventory().removeItem(sellChoice);
                }
            }
        }
        else
            std::cout << "다시 선택해주세요" << std::endl;
    }
}

void GameSession::run() {
    while (true) {
        std::cout << "1. 상점" << std::endl;
        std::cout << "2. 상태창" << std::endl;
        std::cout << "3. 전투" << std::endl;
        std::cout << "4. 게임 종료" << std::endl;

        int input;
        std::cin >> input;

        switch (input) {
        case 1:
            visitShop();
            break;
        case 2:
            player->getStats().showStats();
            break;
        case 3:
            player->getStats().takeDamage(20);
            if (player->getStats().isDead()) {
                gameOver();
            } else {
                std::cout << "You survived the combat.\n";
            }
            break;
        case 4:
            std::cout << "게임을 종료합니다." << std::endl;
            exit(0);
        default:
            std::cout << "다시 선택해주세요" << std::endl;
            system("cls");
        }
    }
}