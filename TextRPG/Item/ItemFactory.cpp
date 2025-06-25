#include "ItemFactory.h"

#include "AtkBoostEffect.h"
#include "CurseEffect.h"
#include "Damage5Effect.h"
#include "DodgeEffect.h"
#include "DoubleAtkEffect.h"
#include "HealEffect.h"
#include "HpBoostEffect.h"

std::vector<std::shared_ptr<Item>> ItemFactory::createItem()
{
    std::vector<std::shared_ptr<Item>> items;
    items.push_back(std::make_shared<Item>("회복 포션", 10, 10, std::make_unique<HealEffect>(50)));
    items.push_back(std::make_shared<Item>("공격력 강화", 40, 3, std::make_unique<AtkBoostEffect>(10)));
    items.push_back(std::make_shared<Item>("체력 강화", 30, 3, std::make_unique<HpBoostEffect>(50)));
    items.push_back(std::make_shared<Item>("저주 물약", 50, 3, std::make_unique<CurseEffect>()));
    items.push_back(std::make_shared<Item>("장막", 70, 2, std::make_unique<Damage5Effect>()));
    items.push_back(std::make_shared<Item>("두번 때리기", 80, 2, std::make_unique<DoubleAtkEffect>()));
    items.push_back(std::make_shared<Item>("회피 주사위", 60, 5, std::make_unique<DodgeEffect>()));
    items.push_back(std::make_shared<Item>("회복 포션", 10, 10, std::make_unique<HealEffect>(50)));
    
    return items;
}
