#include "DodgeEffect.h"
#include "../Character/Character.h"
#include <iostream>

void DodgeEffect::apply(Character& target) {
    target.getStats().dodgeDice();
}

std::unique_ptr<Effect> DodgeEffect::clone() const
{
    return std::make_unique<DodgeEffect>(*this);
}
