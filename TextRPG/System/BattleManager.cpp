#include "BattleManager.h"
#include <iostream>
#include "../System/Util.h"
#include "../System/Logger.h"
#include "../Character/Character.h"
#include "../Monster/Monster.h"
#include "../Monster/MonsterFactory.h"

BattleManager::BattleResult BattleManager::startBattle(Character& player)
{
    std::unique_ptr<Monster> monster = MonsterFactory::CreateMonster(player.getStats().getLevel());
    std::cout << "전투를 시작합니다! 몬스터 : " << monster->getName() << std::endl;
    Logger::getInstance().log("Battle started with " + monster->getName());

    while (!player.getStats().isDead() && !monster->isDead())
    {
        std::cout << player.getName() << "의 HP : " << player.getStats().getHp() << std::endl;
        std::cout << monster->getName() << "의 HP : " << monster->getHp() << std::endl;

        std::cout << "1. 공격\n2. 아이템 사용\n>";
        int choice;
        std::cin >> choice;
        
        while (choice != '1' && choice != '2')
        {
            std::cout << "잘못된 입력입니다. 다시 입력하세요\n>";
            std::cin >> choice; 
        }
        
        if (choice == 1)
        {
            int playerDamage = player.getStats().getAttack();
            monster->takeDamage(playerDamage);
            std::cout << monster->getName() << "에게 " << playerDamage << "의 데미지를 주었습니다" << std::endl;
        }
        else if (choice == 2)
        {
            if (player.getInventory().empty())
            {
                std::cout << "인벤토리가 비었습니다" << std::endl;
                continue;
            }

            player.getInventory().showItems();
            std::cout << "아이템을 선택해주세요\n>";
            int itemIndex;
            std::cin >> itemIndex;

            if (itemIndex >= 1 && itemIndex <= player.getInventory().size())
            {
                Item* item = player.getInventory().getItem(itemIndex - 1);
                item->use(player);
                if (item->isSoldOut())
                {
                    player.getInventory().removeItem(itemIndex - 1);
                }
            }
            else
            {
                std::cout << "잘못된 아이템 사용입니다." << std::endl;
            }
        }

        if (monster->isDead())
            break;

        int monsterDamage = monster->getAttack();
        player.getStats().takeDamage(monsterDamage);
        std::cout << monster->getName() << "이(가) " << monsterDamage << "만큼 데미지를 주었습니다." << std::endl;
    }

    BattleResult result;
    if (player.getStats().isDead())
    {
        std::cout << "YOU DIED" << std::endl;
        result.playerWon = false;
        result.goldGained = 0;
        result.expGained = 0;
        result.itemLooted = nullptr;
    }
    else
    {
        std::cout << "YOU WIN!!" << std::endl;
        result.playerWon = true;
        result.goldGained = Util::getRandomInRange(10, 20);
        result.expGained = 50;
        result.itemLooted = monster->dropLoot();

        if (result.itemLooted != nullptr)
        {
            std::cout << result.itemLooted->getName() << "을(를) 발견했습니다!" << std::endl;
            Logger::getInstance().log("Get the Item(" + result.itemLooted->getName() + ")");
        }
        std::cout << "획득한 경험치 : " << result.expGained << " / 획득한 골드 : " << result.goldGained << std::endl;
        Logger::getInstance().log("Get the exp(" + std::to_string(result.expGained) + ")");
        Logger::getInstance().log("Get the gold(" + std::to_string(result.goldGained) + ")");
    }

    return result;
}

