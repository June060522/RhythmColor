#pragma once
#include <Windows.h>

enum class COLOR
{
    BLACK, BLUE, GREEN, SKYBLUE, RED,
    VIOLET, YELLOW, LIGHT_GRAY, GRAY, LIGHT_BLUE,
    LIGHT_GRREN, MINT, LIGHT_RED, LIGHT_VIOLET,
    LIGHT_YELLOW, WHITE
};

const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

void Init();

void GotoCur(int,int);

void SetColor(int, int);

int GetColor();

int GetBGColor();