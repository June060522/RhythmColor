#include "console.h"
#include<Windows.h>


void Init()
{
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = false;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(hOut, &ConsoleCursor);
    system("mode con cols=150 lines=40");
    SetConsoleTitle(TEXT("Rhythm Color"));
}

void GotoCur(int x, int y)
{
    COORD Cur = { x, y };

    SetConsoleCursorPosition(hOut, Cur);
}