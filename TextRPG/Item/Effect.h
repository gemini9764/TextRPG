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
    HealEffect(int amt) : amount(amt) {}

    /**
     * HealEffect 클래스의 apply 메서드는 대상(Character)의 체력을 회복시키는 효과를 적용합니다.
     *
     * @param target 체력을 회복시킬 대상 Character 객체
     */
    void apply(Character& target) override;
    /**
     * HealEffect 클래스의 clone 메서드는 객체의 복사본을 생성하여 반환합니다.
     *
     * @return HealEffect 객체의 복사본을 저장한 unique_ptr
     */
    std::unique_ptr<Effect> clone() const override;
};
