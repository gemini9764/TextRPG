#pragma once
#include <memory>
#include <string>
#include "../Character/Character.h"
#include "../Shop/Shop.h"

class GameSession
{
private:
    std::unique_ptr<Character> player;
    Shop shop;
    int gold;

    /**
     * @brief 게임 세션의 초기 상태를 설정하는 함수.
     *
     * 플레이어의 이름을 입력받고, 캐릭터 객체를 생성하여 초기화합니다.
     * 상점의 아이템을 재고 정비하고, 초기 금액을 설정합니다.
     * 또한, 플레이어에게 환영 메시지를 출력합니다.
     */
    void initializeGame();
    void gameOver();
    void gameClear();
    
public:
    GameSession();
    void run();
    void visitShop();
};
