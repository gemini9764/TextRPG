#include "CurseEffect.h"
#include "../Character/Character.h"
#include "../System/Util.h"
#include "../Monster/Monster.h"
#include <iostream>

void CurseEffect::apply(Character& target) {
    target.getStats().takeDamage(5);
    int percent = 2 + Util::getRandomInRange(0, 13);
    int extra = target.getStats().getAttack() * (percent / 100);
    target.getStats().additionalDamage(extra);
}

std::unique_ptr<Effect> CurseEffect::clone() const
{
    return std::make_unique<CurseEffect>(*this);
}

