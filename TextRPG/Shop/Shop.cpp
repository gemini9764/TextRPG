#include "Shop.h"
#include <iostream>

#include "../Character/Character.h"
#include "../Item/ItemFactory.h"
#include "../Item/Item.h"

void Shop::initialize()
{
    items.clear();
    items = std::move(ItemFactory::createItem());
}

void Shop::addItem(std::unique_ptr<Item> newItem)
{
    if (newItem == nullptr)
        return;

    for (std::shared_ptr<Item>& item : items)
    {
        if (newItem->getName() == item->getName())
        {
            item->increaseQuantity();
            return;
        }
    }

    items.push_back(std::move(newItem));
}

void Shop::showItem() const
{
    std::cout << "---------- 빡빡이 아저씨의 눈부신 상점 목록 ------------" << '\n';
    for (int i = 0; i < items.size(); i++)
    {
        std::cout << i + 1 << ". " << items[i]->getName()
            << " (가격: " << items[i]->getPrice()
            << ", 수량: " << items[i]->getQuantity() << ")" << '\n';
    }
}

Item* Shop::getItem(int index) const
{
    if (index < 0 || index > items.size())
        return nullptr;
    return items[index].get();
}

bool Shop::purchaseItem(int index, CombatStats& playerStats)
{
    int playerMoney = playerStats.getGold();
    if (index < 1 || index > items.size())
        return false;
    std::shared_ptr<Item>& item = items[index - 1];
    
    if (item->getQuantity() <= 0)
    {
        std::cout << "품절되었습니다!" << '\n';
        return false;
    }
    if (playerMoney < item->getPrice())
    {
        std::cout << "골드가 모자랍니다. 잔액: " << playerMoney << '\n';
        return false;
    }

    char useYn;
    std::cout << "아이템을 구매하시겠습니까?(Y/N)\n>";
    std::cin >> useYn;

    while (useYn != 'Y' && useYn != 'y' && useYn != 'N' && useYn != 'n')
    {
        std::cout << "잘못된 입력입니다. 다시 선택해주세요.\n>";
		std::cin.clear();
		std::cin.ignore();
        std::cin >> useYn;
    }

    if (useYn == 'Y' || useYn == 'y')
    {
        playerMoney -= item->getPrice();
        playerStats.setGold(playerMoney);
        item->decreaseQuantity();
        std::cout << item->getName() << "을(를) 구매하였습니다. 잔액: " << playerMoney << '\n';

        if (item->isSoldOut())
            items.erase(items.begin() + (index - 1));

        return true;
    }
    else
        return false;
}

void Shop::restock()
{
    items.clear();
    initialize();
}
