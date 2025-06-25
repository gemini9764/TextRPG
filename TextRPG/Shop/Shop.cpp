#include "Shop.h"
#include <iostream>
#include "../Item/ItemFactory.h"
#include "../Item/Item.h"

void Shop::initialize()
{
    items.clear();
    items.push_back(ItemFactory::createItem("potion"));
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
    std::cout << "---------- 빡빡이 아저씨의 눈부신 상점 목록 ------------" << std::endl;
    for (int i=0; i < items.size(); i++)
    {
        std::cout << i + 1 << ". " << items[i]->getName()
                  << " (가격: " << items[i]->getPrice()
                  << ", 수량: " << items[i]->getQuantity() << ")" << std::endl;
    }
}

Item* Shop::getItem(int index) const
{
    if (index < 1 || index > items.size())
        return nullptr;
    return items[index - 1].get();
}

bool Shop::purchaseItem(int index, int& playerMoney)
{
    if (index < 1 || index > items.size())
        return false;
    std::shared_ptr<Item>& item = items[index - 1];

    if (item->getQuantity() <= 0)
    {
        std::cout << "품절되었습니다" << std::endl;
        return false;
    }
    if (playerMoney < item->getQuantity())
    {
        std::cout << "골드가 모자랍니다" << std::endl;
        return false;
    }

    char useYn;
    std::cout << "아이템을 구매하시겠습니까?(Y/N)\n>";
    std::cin.get(useYn);
    
    while (useYn != 'Y' && useYn != 'y' && useYn != 'N' && useYn != 'n')
    {
        std::cout << "잘못된 입력입니다. 다시 입력하세요\n>";
        std::cin.get(useYn);     
    }    

    if (useYn == 'Y' || useYn == 'y')
    {
        playerMoney -= item->getPrice();
        item->decreaseQuantity();
        std::cout << item->getName() << "을(를) 구매하였습니다." << std::endl;

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