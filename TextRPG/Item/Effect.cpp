#include "Effect.h"
#include "../Character/Character.h"
#include <iostream>

void HealEffect::apply(Character& target) {
    target.getStats().heal(amount);
}

std::unique_ptr<Effect> HealEffect::clone() const
{
    return std::make_unique<HealEffect>(*this);
}