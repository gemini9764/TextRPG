#include "HpBoostEffect.h"
#include "../Character/Character.h"
#include <iostream>

void HpBoostEffect::apply(Character& target) {
    target.getStats().hpBoost(amount);
}

std::unique_ptr<Effect> HpBoostEffect::clone() const
{
    return std::make_unique<HpBoostEffect>(*this);
}