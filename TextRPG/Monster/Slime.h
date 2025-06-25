#pragma once
#include "Monster.h"

class Slime : public Monster
{
public:
    Slime(int level, bool isBoss = false)
        : Monster("Slime", level, isBoss)
    {
    }
};
