#pragma once
#include "../Item/ItemFactory.h"

class Character;

class BattleManager
{
public:
    struct BattleResult
    {
        bool playerWon = false;
        bool bossMonster = false;
        int goldGained = 0;
        int expGained = 0;
        std::unique_ptr<Item> itemLooted;
    };
    
    BattleResult startBattle(Character& player);
};
