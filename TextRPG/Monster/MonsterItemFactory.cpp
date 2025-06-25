#include "MonsterItemFactory.h"

#include <iostream>
#include <ostream>

#include "../Item/HealEffect.h"
#include "../Item/AtkBoostEffect.h"
#include "../Item/HpBoostEffect.h"
#include "../Item/CurseEffect.h"
#include "../Item/Damage5Effect.h"
#include "../Item/DoubleAtkEffect.h"
#include "../Item/DodgeEffect.h"
#include "../System/Util.h"

std::unique_ptr<Item> MonsterItemFactory::createMonsterItem()
{
    int roll = Util::getRandomInRange(1, 7);

    std::cout << "MonsterItemFactory's roll : " << roll << std::endl;
    
    if (roll == 1)
        return std::make_unique<Item>("회복 포션", 10, 1, std::make_unique<HealEffect>(50));
    else if (roll == 2)
        return std::make_unique<Item>("공격력 강화", 40, 1, std::make_unique<AtkBoostEffect>(10)); 
    else if (roll == 3)
        return std::make_unique<Item>("체력 강화", 30, 1, std::make_unique<HpBoostEffect>(50));
    else if (roll == 4)
        return std::make_unique<Item>("저주 물약", 50, 1, std::make_unique<CurseEffect>());
    else if (roll == 5)
        return std::make_unique<Item>("장막", 70, 1, std::make_unique<Damage5Effect>());
    else if (roll == 6)
        return std::make_unique<Item>("두번 때리기", 80, 1, std::make_unique<DoubleAtkEffect>());
    else if (roll == 7)
        return std::make_unique<Item>("회피 주사위", 60, 1, std::make_unique<DodgeEffect>());

    return nullptr;
}
