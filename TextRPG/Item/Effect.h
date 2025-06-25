#pragma once
#include <memory>

class Character;

/**
 * Effect 클래스는 다양한 효과를 정의하기 위한 추상 클래스입니다.
 * 이 클래스는 파생 클래스가 구체적인 효과를 구현할 수 있도록 인터페이스를 제공합니다.
 */
class Effect
{
public:
    virtual ~Effect() = default;
    virtual void apply(Character& target) = 0;
    virtual std::unique_ptr<Effect> clone() const = 0;
};