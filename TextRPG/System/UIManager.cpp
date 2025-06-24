#include "UIManager.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

#define UP 0
#define DOWN 1
#define SUBMIT 2

void UIManager::init()
{
    system("mode con cols=200 lines 50 | title Team Four G4ME");
    title();
}

void UIManager::title()
{
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "=======================================================================================================================\n";
    std::cout << "=        ===============================        ===============================      ========  ====  =====  ==        =\n";
    std::cout << "====  ==================================  ====================================   ==   ======   ====   ===   ==  =======\n";
    std::cout << "====  ==================================  ====================================  ====  =====    ====  =   =  ==  =======\n";
    std::cout << "====  ======   ====   ===  =  = ========  =========   ===  =  ==  =   ========  ==========  =  ====  == ==  ==  =======\n";
    std::cout << "====  =====  =  ==  =  ==        =======      ====     ==  =  ==    =  =======  =========  ==  ====  =====  ==      ===\n";
    std::cout << "====  =====     =====  ==  =  =  =======  ========  =  ==  =  ==  ============  ===   ==  ===  ====  =====  ==  =======\n";
    std::cout << "====  =====  ======    ==  =  =  =======  ========  =  ==  =  ==  ============  ====  ==         ==  =====  ==  =======\n";
    std::cout << "====  =====  =  ==  =  ==  =  =  =======  ========  =  ==  =  ==  ============   ==   =======  ====  =====  ==  =======\n";
    std::cout << "====  ======   ====    ==  =  =  =======  =========   ====    ==  =============      ========  ====  =====  ==        =\n";
    std::cout << "=======================================================================================================================\n";
    std::cout << "\n";
    std::cout << "\n";    
}

void UIManager::infoDraw()
{
    system("cls");
    std::cout << "\n\n";
    std::cout << "               Team : 4조       \n\n";
    std::cout << "         김연지  김태연  남승윤 \n";
    std::cout << "            박진권     이선형   \n";
    std::cout << "\n\n";
    std::cout << "       내일배움캠프 TextRPG 과제 \n";
    std::cout << "스페이스 바를 누르면 메인화면으로 이동합니다.";

    while (1) {
        if (keyControl() == SUBMIT) {
            break;
        }
    }
}

int UIManager::menuDraw()
{
    int x = 50;
    int y = 15;
    gotoXY(x-2, y);
    std::cout << "> GAME START";
    gotoXY(x, y+1);
    std::cout << "GAME INFO";
    gotoXY(x, y+2);
    std::cout << "  QUIT";
	
    while (1) {
        int n = keyControl();
        switch(n){
        case UP: {
                if (y>15) { // y는 15~17까지만 이동 
                    gotoXY(x-2,y);
                    std::cout << " ";
                    gotoXY(x-2, --y);
                    std::cout << ">";
                } 
                break;
        }
        case DOWN: {
                if(y<17){
                    gotoXY(x-2,y);
                    std::cout << " ";
                    gotoXY(x-2,++y);
                    std::cout << ">";
                }
                break;
        }
			
        case SUBMIT: {
                return y-15;
        }
        }
    }
}

int UIManager::keyControl()
{
    char temp = _getch();
	
    if(temp == 'w' || temp =='W')
        return UP;
    
    else if (temp == 's' || temp == 'S')
        return DOWN;
    
    else if (temp == 32)
        return SUBMIT;
    
    return -1;
}

void UIManager::gotoXY(int x, int y)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consoleHandle, pos);
}