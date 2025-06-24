#include "MonsterItemFactory.h"
#include "../Item/Effect.h"
#include "../System/Util.h"

std::unique_ptr<Item> MonsterItemFactory::createMonsterItem()
{
    int roll = Util::getRandomInRange(1, 2);

    if (roll == 1)
    {
        return std::make_unique<Item>("potion", 0, 1, std::make_unique<HealEffect>(15));
    }
}
