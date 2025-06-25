#pragma once
#include <memory>
#include "../Character/Character.h"
#include "../Shop/Shop.h"

class GameSession
{
private:
    std::unique_ptr<Character> player;
    Shop shop;

    /**
     * @brief 게임 세션을 초기화합니다.
     *
     * 사용자가 이름을 입력하고 이를 바탕으로 플레이어 캐릭터를 생성합니다.
     * 생성된 캐릭터는 초기 스탯으로 설정되며, 레벨 1, HP 200, ATK 30, 경험치 0, 골드 0값을 가집니다.
     * 또한, 상점의 재고를 초기화하여 상점의 기본 상태를 설정합니다.
     *
     * 이 메서드는 게임 세션의 시작이나 게임 오버 시 호출되어
     * 새로운 게임 세션을 시작하기 위한 준비를 수행합니다.
     *
     * @note 플레이어의 이름은 입력을 통해 설정되며, 게임 시작 시 환영 메시지가 출력됩니다.
     */
    void initializeGame();
    void gameOver();
    void gameClear();
    
public:
    GameSession();
    void run();
    void visitShop();
};
