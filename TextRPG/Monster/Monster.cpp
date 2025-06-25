#include "Monster.h"

#include <iostream>

Monster::Monster(std::string name, int level, bool isBoss)
    : monsterName(name),
      hp(Util::getRandomInRange(static_cast<int>(level * 20),
                                static_cast<int>(level * 30))),
      atk(Util::getRandomInRange(static_cast<int>(level * 5),
                                 static_cast<int>(level * 10)))
{
    if (isBoss)
    {
        monsterName += " Lord";
        hp = static_cast<int>(hp * 1.5);
        atk = static_cast<int>(hp * 1.5);
    }
}