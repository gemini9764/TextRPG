#pragma once
#include <memory>

class Character;

class Effect
{
public:
    virtual ~Effect() = default;
    virtual void apply(Character& target) = 0;
    virtual std::unique_ptr<Effect> clone() const = 0;
};

class HealEffect : public Effect
{
private:
    int amount;
    
public:
    HealEffect(int amt);
    void apply(Character& target) override;
    std::unique_ptr<Effect> clone() const override;
};
