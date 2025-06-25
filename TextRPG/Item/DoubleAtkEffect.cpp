#include "DoubleAtkEffect.h"
#include "../Character/Character.h"
#include <iostream>

void DoubleAtkEffect::apply(Character& target) {
    target.getStats().doubleHit();
}

std::unique_ptr<Effect> DoubleAtkEffect::clone() const
{
    return std::make_unique<DoubleAtkEffect>(*this);
}

