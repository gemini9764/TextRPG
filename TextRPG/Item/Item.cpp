#include "Item.h"
#include <iostream>

#include "../Character/Character.h"

void Item::use(Character& target)
{
    if (quantity <= 0)
    {
        std::cout << "아이템을 모두 사용하셨습니다" << std::endl;
        return;
    }

    char useYn;
    std::cout << "아이템을 사용하시겠습니까?(Y/N)\n>";
    std::cin.get(useYn);
    
    while (useYn != 'Y' && useYn != 'y' && useYn != 'N' && useYn != 'n')
    {
        std::cout << "잘못된 입력입니다. 다시 입력하세요\n>";
        std::cin.get(useYn);     
    }

    if (useYn == 'Y' || useYn == 'y')
    {
        effect->apply(target);
        quantity -= 1;
    }
}

std::unique_ptr<Item> Item::clone() const
{
    return std::make_unique<Item>(name, price, quantity, effect->clone());
}