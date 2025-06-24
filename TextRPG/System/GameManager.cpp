#include "GameManager.h"
#include "GameSession.h"
#include <iostream>

void GameManager::run()
{
    ui.init();
    int menuCode = ui.menuDraw();

    while (true)
    {
        switch (menuCode)
        {
        case 0:
            gamestart();
            break;
        case 1:
            ui.infoDraw();
            break;
        case 2:
            return;
        }
        system("cls");
    }
}

void GameManager::gamestart()
{
    system("cls");
    GameSession game;
    game.run();
}