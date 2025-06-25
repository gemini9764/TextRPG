#pragma once
#include "Monster.h"

class Dragon : public Monster
{
public:
    Dragon(int level, bool isBoss = false)
        : Monster("Dragon", level, isBoss)
    {
    }
};
