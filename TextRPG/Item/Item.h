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
