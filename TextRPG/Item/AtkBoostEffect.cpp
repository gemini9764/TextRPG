#include "AtkBoostEffect.h"
#include "../Character/Character.h"
#include <iostream>

void AtkBoostEffect::apply(Character& target) {
    target.getStats().atkBoost(amount);
}

std::unique_ptr<Effect> AtkBoostEffect::clone() const
{
    return std::make_unique<AtkBoostEffect>(*this);
}