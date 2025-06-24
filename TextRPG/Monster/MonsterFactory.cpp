#include "MonsterFactory.h"
#include "Goblin.h"
#include "Orc.h"
#include "Troll.h"
#include "Dragon.h"
#include "Slime.h"
#include "../System/Utility.h"

std::unique_ptr<Monster> MonsterFactory::CreateMonster(int playerLevel)
{
    bool isBoss = (playerLevel >= 10);
    int type = Utility::getRandomInRange(1, 5);
    switch (type)
    {
        case 1:
            return std::make_unique<Slime>(playerLevel, isBoss);
        case 2:
            return std::make_unique<Orc>(playerLevel, isBoss);
        case 3:
            return std::make_unique<Troll>(playerLevel, isBoss);
        case 4:
            return std::make_unique<Dragon>(playerLevel, isBoss);
        case 5:
            return std::make_unique<Goblin>(playerLevel, isBoss);
        default:
            return std::make_unique<Slime>(playerLevel, isBoss);
    }
}
