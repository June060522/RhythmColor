#pragma once
#include<iostream>

enum class KEY
{
	UP, DOWN, LEFT, RIGHT, W, A, S, D, Space, ESC
};

enum class Mode
{
	Play, Credits, Exit
};

const int ScreenX = 118;
const int ScreenY = 30;

int KeyController();

void PrintTitleAndSpace();

void PressSpace();

int PrintMenu();

int PrintStageSelect();

void PrintCredit();

void CreditText(int x, int& curY, std::string printS);

void PrintNum(int num, int posX, int posY, bool& isTwinkle, bool isSelect = false, int stage = 0);

void Loading();

void PrintLoading(bool isLeft, int posX, int posY);

void PrintESC();