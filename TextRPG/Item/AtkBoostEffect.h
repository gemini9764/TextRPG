#pragma once
#include "Effect.h"

class AtkBoostEffect : public Effect
{
private:
    int amount;
    
public:
    AtkBoostEffect(int amt) : amount(amt) {}

    void apply(Character& target) override;
    std::unique_ptr<Effect> clone() const override;
};
