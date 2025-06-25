#pragma once
#include "Effect.h"

class HpBoostEffect : public Effect
{
private:
    int amount;
    
public:
    HpBoostEffect(int amt) : amount(amt) {}

    void apply(Character& target) override;
    std::unique_ptr<Effect> clone() const override;
};

