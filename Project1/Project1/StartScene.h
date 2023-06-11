#pragma once
enum class KEY
{
	UP, DOWN, LEFT, RIGHT, Space, ESC
};

enum class Mode
{
	Play, Credits, Exit
};

const int ScreenX = 118;
const int ScreenY = 30;

void PrintTitleAndSpace();

void PressSpace();

int PrintMenu();

void PrintStageSelect();

void PrintCredit();

void CreditText(int x, int& curY, std::string printS);

void PrintNum(int num, int posX, int posY, bool isSelect = false, int stage = 0);

void Loading();

void PrintLoading(bool isLeft, int posX, int posY);