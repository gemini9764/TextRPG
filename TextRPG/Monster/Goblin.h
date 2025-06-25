#pragma once
#include "Monster.h"

class Goblin : public Monster
{
public:
    Goblin(int level, bool isBoss = false)
        : Monster("Goblin", level)
    {
    }
};
