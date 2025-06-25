#pragma once
#include <memory>
#include <string>
#include "Effect.h"

class Character;

class Item
{
private:
    std::string name;
    int price;
    int quantity;
    std::unique_ptr<Effect> effect;
    
public:
    Item(const std::string& name, int price, int quantity, std::unique_ptr<Effect> eff)
        : name(name), price(price), quantity(quantity), effect(std::move(eff)) {}

    /**
     * @brief 지정된 Character 객체를 대상으로 현재 Item을 사용합니다.
     *
     * 이 메서드는 대상(Character)에게 아이템 효과를 적용하고, 적용 후 아이템의 수량을 감소시킵니다.
     * 사용 여부를 묻는 입력이 포함되어 있으며, 남은 수량이 없으면 사용이 불가능합니다.
     *
     * @param target 효과를 적용할 Character 객체 (대상).
     */
    void use(Character& target);

    const std::string& getName() const { return name; }
    int getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    void decreaseQuantity() { if (quantity > 0) --quantity; }
    void increaseQuantity() { if (quantity > 0) ++quantity; }
    bool isSoldOut() const { return quantity <= 0; }

    /**
     * @brief 현재 Item 객체의 복제본을 생성합니다.
     *
     * 이 메서드는 현재 객체를 동일한 값과 상태를 가진 새로운 Item 객체로 복제하여 반환합니다.
     * 내부적으로 포함된 Effect 객체도 깊은 복제를 수행합니다.
     *
     * @return 현재 Item 객체의 복제본을 나타내는 std::unique_ptr<Item> 객체.
     */
    std::unique_ptr<Item> clone() const;
};
