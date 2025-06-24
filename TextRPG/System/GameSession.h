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

    void initializeGame();
    void gameOver();
    void gameClear();
    
public:
    GameSession();
    void run();
    void visitShop();
};
