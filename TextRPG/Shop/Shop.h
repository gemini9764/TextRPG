#pragma once
#include <memory>
#include <vector>

class Item;
class CombatStats;

class Shop
{
private:
    std::vector<std::shared_ptr<Item>> items;

public:
    /**
     * @brief 상점에서 보유한 아이템 목록을 초기화합니다.
     *
     * 현재 상점에 등록된 모든 아이템을 제거하고 초기 항목으로 대체합니다.
     * 해당 메서드는 상점의 기본 상태를 설정하는 데 사용됩니다.
     * 예를 들어, 상점이 처음 생성되거나 재고를 리셋해야 할 때 호출될 수 있습니다.
     */
    void initialize();
    
    void addItem(std::unique_ptr<Item> newItem);
    void showItem() const;
    Item* getItem(int index) const;
    int getItemSize() const { return items.size(); }

    /**
     * @brief 상점에서 특정 아이템을 구매합니다.
     *
     * 주어진 인덱스의 아이템을 구매하려고 시도하며, 구매 조건(재고 유무, 금액 충족 여부 등)을 확인합니다.
     * 조건이 충족되면 플레이어의 골드가 감소하고 아이템 재고가 줄어듭니다.
     * 또한, 아이템 재고가 소진되었을 경우 상점 목록에서 해당 아이템이 제거됩니다.
     *
     * @param index 구매를 시도할 아이템의 인덱스 (1부터 시작).
     * @param playerStats 플레이어의 전투 스탯 정보를 담은 객체. 구매 시 골드 정보가 사용되며 업데이트됩니다.
     * @return 구매 성공 여부를 나타내는 boolean 값. 성공 시 true, 실패 시 false.
     */
    bool purchaseItem(int index, CombatStats& playerStats);
    /**
     * @brief 상점의 아이템 재고를 초기화합니다.
     *
     * 상점에서 보유한 아이템 목록을 초기화하고, 아이템을 다시 설정합니다.
     * 이전에 설정된 모든 아이템은 제거되며, 기본 구성으로 재고가 채워집니다.
     * 주로 게임 시작 시 또는 재고를 새로 채워야 할 때 호출됩니다.
     */
    void restock();
};