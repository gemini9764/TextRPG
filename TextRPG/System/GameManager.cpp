#include "GameManager.h"
#include "GameSession.h"

void GameManager::run()
{
    ui.initialize();
    int menuCode = ui.menuDraw();

    while (true)
    {
        switch (menuCode)
        {
        case 0:
            // GameSession::run()
            gameStart();
            break;
        case 1:
            // 조 정보
            ui.infoDraw();
            break;
        case 2:
            return;
        }
        system("cls");
    }
}

void GameManager::gameStart()
{
    system("cls");
    GameSession game;
    game.run();
}