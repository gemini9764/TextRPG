#pragma once
#include <memory>
#include "Monster.h"

class MonsterFactory
{
public:
    static std::unique_ptr<Monster> CreateMonster(int playerLevel);
};
