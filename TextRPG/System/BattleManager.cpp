#include "BattleManager.h"
#include <iostream>
#include <limits>

#include "../Monster/MonsterFactory.h"

BattleManager::BattleResult BattleManager::startBattle(Character& player)
{
    std::unique_ptr<Monster> monster = MonsterFactory::CreateMonster(player.getStats().getLevel());
    std::cout << "전투를 시작합니다! 몬스터 : " << monster->getName() << std::endl;

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
            int damage = player.getStats().getAttack();
        }
    }
}

