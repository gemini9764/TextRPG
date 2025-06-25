#pragma once
#include "Monster.h"

class Orc : public Monster
{
public:
    Orc(int level, bool isBoss = false)
        : Monster("Orc", level, isBoss)
    {
    }
};
