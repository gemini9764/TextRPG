#pragma once
#include "../Item/ItemFactory.h"

class Character;

class BattleManager
{
public:
    struct BattleResult
    {
        bool playerWon;
        bool bossMonster;
        int goldGained;
        int expGained;
        std::unique_ptr<Item> itemLooted;
    };
    
    BattleResult startBattle(Character& player);
};
