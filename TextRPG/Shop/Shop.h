#pragma once
#include <memory>
#include <vector>

class Item;

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
    
    /**
     * @brief 주어진 인덱스의 아이템을 구매합니다.
     *
     * 상점에서 선택된 아이템을 구매하려고 시도합니다.
     * 구매하려는 아이템의 번호와 플레이어의 현재 소지 금액을 참조하여 구매 가능 여부를 판단하며, 구매 요청을 처리합니다.
     * 아이템 구매 성공 시 플레이어의 소지 금액이 차감되고, 해당 아이템의 재고도 감소합니다.
     *
     * @param index 구매하려는 아이템의 인덱스 (1부터 시작).
     * @param playerMoney 플레이어의 현재 소지 금액 (참조로 전달됨).
     * @return 구매 성공 시 true, 실패 시 false를 반환.
     */
    bool purchaseItem(int index, int& playerMoney);
    /**
     * @brief 상점의 아이템 재고를 초기화합니다.
     *
     * 상점에서 보유한 아이템 목록을 초기화하고, 아이템을 다시 설정합니다.
     * 이전에 설정된 모든 아이템은 제거되며, 기본 구성으로 재고가 채워집니다.
     * 주로 게임 시작 시 또는 재고를 새로 채워야 할 때 호출됩니다.
     */
    void restock();
};