#include "console.h"
#include <iostream>
#include<Windows.h>

void Init()
{
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);
    srand((unsigned)time(NULL));
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = false;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(hOut, &ConsoleCursor);
    SetFontSize(20, 20, 20);
    system("mode  con lines=30   cols=130");
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

void SetFontSize(UINT _weight, UINT _sizex, UINT _sizey)
{
    static CONSOLE_FONT_INFOEX font;
    font.cbSize = sizeof(font);
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFontEx(hout, false, &font);
    font.FontWeight = _weight;
    font.dwFontSize.X = _sizex;
    font.dwFontSize.Y = _sizey;
    SetCurrentConsoleFontEx(hout, false, &font);
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