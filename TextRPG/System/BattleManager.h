#pragma once
#include "../Character/Character.h"
#include "../Monster/Monster.h"
#include "../Item/ItemFactory.h"

class BattleManager
{
public:
    struct BattleResult
    {
        bool playerWon;
        int goldGained;
        int expGained;
        std::unique_ptr<Item> itemLooted;
    };
    
    BattleResult startBattle(Character& player);
};
