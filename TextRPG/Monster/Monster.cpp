#include "Monster.h"

Monster::Monster(std::string name, int level, bool isBoss, float healthMultiply, float attakMultiply)
    : name(name),
      hp(Util::getRandomInRange(static_cast<int>(level * 20 * healthMultiply),
                                static_cast<int>(level * 30 * healthMultiply))),
      atk(Util::getRandomInRange(static_cast<int>(level * 5 * attakMultiply),
                                 static_cast<int>(level * 10 * attakMultiply)))
{
    if (isBoss)
    {
        name += " Lord";
    }
}
