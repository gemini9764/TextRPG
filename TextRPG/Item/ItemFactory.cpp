#include "ItemFactory.h"
#include "Effect.h"

std::unique_ptr<Item> ItemFactory::createItem(const std::string& id)
{
    if (id == "potion")
    {
        return std::make_unique<Item>("회복 포션", 50, 5, std::make_unique<HealEffect>(25));
    }
    return nullptr;
}