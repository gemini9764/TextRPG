#include "MonsterFactory.h"

#include <iostream>
#include <ostream>

#include "Goblin.h"
#include "Orc.h"
#include "Troll.h"
#include "Dragon.h"
#include "Slime.h"
#include "../Item/ItemFactory.h"
#include "../System/Util.h"

std::unique_ptr<Monster> MonsterFactory::CreateMonster(int playerLevel)
{
    std::unique_ptr<Monster> monster;
    bool isBoss = playerLevel >= 10 ? true : false;
    int type = Util::getRandomInRange(1, 5);
    switch (type)
    {
        case 1:
            monster = std::make_unique<Slime>(playerLevel, isBoss);
            break;
        case 2:
            monster = std::make_unique<Orc>(playerLevel, isBoss);
            break;
        case 3:
            monster = std::make_unique<Troll>(playerLevel, isBoss);
            break;
        case 4:
            monster = std::make_unique<Dragon>(playerLevel, isBoss);
            break;
        case 5:
            monster = std::make_unique<Goblin>(playerLevel, isBoss);
            break;
        default:
            monster = std::make_unique<Slime>(playerLevel, isBoss);
    }
    
    monster->setLoot();
    return monster;
}
