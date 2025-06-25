#pragma once
#include "Monster.h"

class Troll : public Monster
{
public:
    Troll(int level, bool isBoss = false)
        : Monster("Troll", level)
    {
    }
};
