#pragma once
#include <memory>

class Character;

class Effect
{
public:
    virtual ~Effect() = default;
    virtual void apply(Character& target) = 0;
    virtual std::unique_ptr<Effect> clone() const = 0;
};