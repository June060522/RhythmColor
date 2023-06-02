#include "console.h"
#include <iostream>
#include<Windows.h>

void Init()
{
    srand((unsigned)time(NULL));
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

void SetColor(int _color, int _bgColor)
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hOut, (_bgColor << 4) | _color);
}

int GetColor()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;

    GetConsoleScreenBufferInfo(hOut, &info);
    int color = info.wAttributes & 0xf;
    return color;
}

int GetBGColor()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;

    GetConsoleScreenBufferInfo(hOut, &info);
    int color = (info.wAttributes & 0xf) >> 4;
    return color;
}