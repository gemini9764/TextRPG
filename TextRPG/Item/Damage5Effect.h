#pragma once
#include "Effect.h"

class Damage5Effect : public Effect
{
    
public:
    void apply(Character& target) override;
    std::unique_ptr<Effect> clone() const override;
};

