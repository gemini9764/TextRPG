#include "Damage5Effect.h"
#include "../Character/Character.h"
#include <iostream>

void Damage5Effect::apply(Character& target) {
    target.getStats().damage5();
}

std::unique_ptr<Effect> Damage5Effect::clone() const
{
    return std::make_unique<Damage5Effect>(*this);
}
