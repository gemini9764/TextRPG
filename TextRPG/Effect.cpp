#include "Effect.h"
#include "Character.h"
#include <iostream>

HealEffect::HealEffect(int amt) : amount(amt) {}

void HealEffect::apply(Character& target) {
    target.getStats().heal(amount);
}

std::unique_ptr<Effect> HealEffect::clone() const
{
    return std::make_unique<HealEffect>(*this);
}