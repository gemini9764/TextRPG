#pragma once
#include "Effect.h"

class CurseEffect : public Effect
{
public:
    void apply(Character& target) override;
    std::unique_ptr<Effect> clone() const override;
};
