#pragma once
#include <memory>
#include <string>
#include "Character.h"
#include "Shop.h"

class GameSession
{
private:
    std::unique_ptr<Character> player;
    Shop shop;
    int gold;
    std::string playerName;

    void initializeGame();
    void gameOver();
    void gameClear();
    
public:
    GameSession(const std::string& name);
    void run();
    void visitShop();
};
