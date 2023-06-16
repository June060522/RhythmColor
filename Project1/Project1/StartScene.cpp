#include <iostream>
#include <algorithm>
#include "StartScene.h"
#include "console.h"
#include <io.h>
#include <fcntl.h>
#include <conio.h>

using namespace std;

int mode;

int printMenuIdx = 0;

int KeyController()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		return (int)KEY::UP;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		return (int)KEY::DOWN;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		return (int)KEY::LEFT;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		return (int)KEY::RIGHT;
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		return (int)KEY::Space;
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		return (int)KEY::ESC;
	if (GetAsyncKeyState(0x57) & 0x8000)
		return (int)KEY::W;
	if (GetAsyncKeyState(0x41) & 0x8000)
		return (int)KEY::A;
	if (GetAsyncKeyState(0x53) & 0x8000)
		return (int)KEY::S;
	if (GetAsyncKeyState(0x44) & 0x8000)
		return (int)KEY::D;

	return -1;
}

bool InputSpace(const wchar_t* text)
{
	mode = _setmode(_fileno(stdout), _O_U16TEXT);
	clock_t curtime, oldtime;
	oldtime = clock();
	SetColor(rand() % 15 + 1, (int)COLOR::BLACK);
	wcout << text << endl;
	mode = _setmode(_fileno(stdout), _O_TEXT);
	++printMenuIdx;
	if (printMenuIdx > 5)
		printMenuIdx = 0;
	while (true)
	{
		curtime = clock();
		if (KeyController() == (int)KEY::Space)
			return true;
		if (curtime - oldtime > 60)
		{
			oldtime = curtime;
			break;
		}
	}
	return false;
}

bool InputSpace(const wchar_t* text, int& key, int& y)
{
	int x = 45;
	mode = _setmode(_fileno(stdout), _O_U16TEXT);
	clock_t curtime, oldtime;
	oldtime = clock();
	SetColor(rand() % 15 + 1, (int)COLOR::BLACK);
	wcout << text << endl;
	mode = _setmode(_fileno(stdout), _O_TEXT);
	++printMenuIdx;
	if (printMenuIdx > 5)
		printMenuIdx = 0;
	while (true)
	{
		key = KeyController();
		curtime = clock();
		if (key == (int)KEY::UP)
		{
			GotoCur(x + 2, y);
			cout << "\b\b";
			cout << "  ";
			y--;
			y = clamp(y, 20, 22);
			GotoCur(x, y);
			cout << "▷";
			key = -1;
			Sleep(116);
		}
		else if (key == (int)KEY::DOWN)
		{
			GotoCur(x + 2, y);
			cout << "\b\b";
			cout << "  ";
			y++;
			y = clamp(y, 20, 22);
			GotoCur(x, y);
			cout << "▷";
			key = -1;
			Sleep(116);
		}
		else if (key == (int)KEY::Space)
			return true;
		if (curtime - oldtime > 90)
		{
			oldtime = curtime;
			break;
		}
	}
	return false;
}

void PrintSpace(string sPrint)
{
	GotoCur(55, 20);
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	mode = _setmode(_fileno(stdout), _O_TEXT);
	cout << sPrint;
	clock_t curtime, oldtime;
	oldtime = clock();
	while (true)
	{
		curtime = clock();
		if (curtime - oldtime > 30)
		{
			break;
		}
	}

}

void PrintTitleAndSpace()
{
	int x = 18;
	int y = 5;
	mode = _setmode(_fileno(stdout), _O_U16TEXT);
	printMenuIdx = 0;
	while (true)
	{
		x = 18;
		y = 5;

		if (printMenuIdx == 0)
		{
			PrintSpace("Press 'Space' to Start");
			GotoCur(x, y + printMenuIdx);
			if (InputSpace(L"██████╗ ██╗  ██╗██╗   ██╗████████╗██╗  ██╗███╗   ███╗     ██████╗ ██████╗ ██╗      ██████╗ ██████╗ "))
				return;
		}
		else if (printMenuIdx == 1)
		{
			PrintSpace("                      ");
			GotoCur(x, y + printMenuIdx);
			if (InputSpace(L"██╔══██╗██║  ██║╚██╗ ██╔╝╚══██╔══╝██║  ██║████╗ ████║    ██╔════╝██╔═══██╗██║     ██╔═══██╗██╔══██╗"))
				return;
		}
		else if (printMenuIdx == 2)
		{
			PrintSpace("Press 'Space' to Start");
			GotoCur(x, y + printMenuIdx);
			if (InputSpace(L"██████╔╝███████║ ╚████╔╝    ██║   ███████║██╔████╔██║    ██║     ██║   ██║██║     ██║   ██║██████╔╝"))
				return;
		}
		else if (printMenuIdx == 3)
		{
			PrintSpace("                      ");
			GotoCur(x, y + printMenuIdx);
			if (InputSpace(L"██╔══██╗██╔══██║  ╚██╔╝     ██║   ██╔══██║██║╚██╔╝██║    ██║     ██║   ██║██║     ██║   ██║██╔══██╗"))
				return;
		}
		else if (printMenuIdx == 4)
		{
			PrintSpace("Press 'Space' to Start");
			GotoCur(x, y + printMenuIdx);
			if (InputSpace(L"██║  ██║██║  ██║   ██║      ██║   ██║  ██║██║ ╚═╝ ██║    ╚██████╗╚██████╔╝███████╗╚██████╔╝██║  ██║"))
				return;
		}
		else if (printMenuIdx == 5)
		{
			PrintSpace("                      ");
			GotoCur(x, y + printMenuIdx);
			if (InputSpace(L"╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝      ╚═╝   ╚═╝  ╚═╝╚═╝     ╚═╝     ╚═════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝  ╚═╝"))
				return;
		}
	}
}

void PressSpace()
{
	int x = 55;
	int y = 20;
	PrintTitleAndSpace();
	GotoCur(x, y);
	mode = _setmode(_fileno(stdout), _O_TEXT);
	cout << "                      ";
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
}

int PrintMenu()
{
	Sleep(200);
	int key = 0;
	int x = 48, y = 20;
	int screenX, screenY;
	GotoCur(x, y++);
	cout << "Play";
	GotoCur(x, y++);
	cout << "Credits";
	GotoCur(x, y++);
	cout << "Exit";
	y = 20;
	screenX = 18;
	screenY = 5;
	GotoCur(45, y);
	cout << "▷";
	while (true)
	{
		screenX = 18;
		screenY = 5;

		if (printMenuIdx == 0)
		{
			GotoCur(screenX, screenY + printMenuIdx);
			if (InputSpace(L"██████╗ ██╗  ██╗██╗   ██╗████████╗██╗  ██╗███╗   ███╗     ██████╗ ██████╗ ██╗      ██████╗ ██████╗ ", key, y))
				return y - 20;
		}
		else if (printMenuIdx == 1)
		{
			GotoCur(screenX, screenY + printMenuIdx);
			if (InputSpace(L"██╔══██╗██║  ██║╚██╗ ██╔╝╚══██╔══╝██║  ██║████╗ ████║    ██╔════╝██╔═══██╗██║     ██╔═══██╗██╔══██╗", key, y))
				return y - 20;
		}
		else if (printMenuIdx == 2)
		{
			GotoCur(screenX, screenY + printMenuIdx);
			if (InputSpace(L"██████╔╝███████║ ╚████╔╝    ██║   ███████║██╔████╔██║    ██║     ██║   ██║██║     ██║   ██║██████╔╝", key, y))
				return y - 20;
		}
		else if (printMenuIdx == 3)
		{
			GotoCur(screenX, screenY + printMenuIdx);
			if (InputSpace(L"██╔══██╗██╔══██║  ╚██╔╝     ██║   ██╔══██║██║╚██╔╝██║    ██║     ██║   ██║██║     ██║   ██║██╔══██╗", key, y))
				return y - 20;
		}
		else if (printMenuIdx == 4)
		{
			GotoCur(screenX, screenY + printMenuIdx);
			if (InputSpace(L"██║  ██║██║  ██║   ██║      ██║   ██║  ██║██║ ╚═╝ ██║    ╚██████╗╚██████╔╝███████╗╚██████╔╝██║  ██║", key, y))
				return y - 20;
		}
		else if (printMenuIdx == 5)
		{
			GotoCur(screenX, screenY + printMenuIdx);
			if (InputSpace(L"╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝      ╚═╝   ╚═╝  ╚═╝╚═╝     ╚═╝     ╚═════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝  ╚═╝", key, y))
				return y - 20;
		}
	}
	return -1;
}

int PrintStageSelect()
{
	Loading();
	int curSelectX = 1;
	int curSelectY = 0;
	clock_t curtime, oldtime;
	int num = -1;
	bool isTwinkle = true;
	while (true)
	{
		PrintESC();
		for (int i = 0; i < 3; i++)
		{
			for (int j = 1; j <= 10; j++)
			{
				if (i * 10 + j == curSelectX + curSelectY * 10)
					PrintNum(i * 10 + j, 12 * (j - 1) + 6, 9 * i + 2, isTwinkle, true, (j + i * 10 - 1) / 5);
				else
					PrintNum(i * 10 + j, 12 * (j - 1) + 6, 9 * i + 2, isTwinkle);
			}
		}
		int num = KeyController();
		if (num == (int)KEY::W || num == (int)KEY::UP)
			curSelectY = clamp(--curSelectY, 0, 2);
		else if (num == (int)KEY::S || num == (int)KEY::DOWN)
			curSelectY = clamp(++curSelectY, 0, 2);
		else if (num == (int)KEY::A || num == (int)KEY::LEFT)
			curSelectX = clamp(--curSelectX, 1, 10);
		else if (num == (int)KEY::D || num == (int)KEY::RIGHT)
			curSelectX = clamp(++curSelectX, 1, 10);
		else if (num == (int)KEY::Space)
			return curSelectY * 10 + curSelectX;
		else if (num == (int)KEY::ESC)
		{
			Loading();
			break;
		}
		oldtime = clock();
		while (true)
		{
			curtime = clock();
			if (curtime - oldtime > 90)
			{
				oldtime = curtime;
				break;
			}
		}
	}
	return -1;
}

void PrintCredit()
{
	Loading();
	int key = -1;
	string printS;
	int x = 60;
	int y = 29;
	int curY;
	while (y > -5 && key != (int)KEY::ESC)
	{
		PrintESC();
		SetColor((int)COLOR::RED, (int)COLOR::BLACK);
		curY = y--;
		printS = "Developer And Level Designer";
		CreditText(x, curY, printS);
		printS = "June";
		CreditText(x, curY, printS);
		curY++;

		SetColor((int)COLOR::BLUE, (int)COLOR::BLACK);
		printS = "Cooperator";
		CreditText(x, curY, printS);
		printS = "JunYoung Teacher";
		CreditText(x, curY, printS);
		curY++;

		SetColor((int)COLOR::YELLOW, (int)COLOR::BLACK);
		printS = "Reference Game";
		CreditText(x, curY, printS);
		printS = "COLORFUL RECOLOR";
		CreditText(x, curY, printS);
		curY++;

		SetColor((int)COLOR::GREEN, (int)COLOR::BLACK);
		printS = "Music Composer";
		CreditText(x, curY, printS);
		printS = "Waterfall - Mewpot Music";
		CreditText(x, curY, printS);
		printS = "glow up - DHDMUSIC";
		CreditText(x, curY, printS);
		printS = "Fresh Five - DHDMUSIC";
		CreditText(x, curY, printS);
		printS = "Fashionable - KORANDRINO";
		CreditText(x, curY, printS);
		printS = "Chill Hip Hop Livestyle Vlog - Silent Station";
		CreditText(x, curY, printS);
		printS = "Breakthrough - Infraction";
		CreditText(x, curY, printS);
		printS = "Sailing Boat - LEXMusic";
		CreditText(x, curY, printS);
		curY++;

		SetColor((int)COLOR::VIOLET, (int)COLOR::BLACK);
		printS = "Effect Composer";
		CreditText(x, curY, printS);
		printS = "Button Click - Mike Koenig";
		CreditText(x, curY, printS);
		printS = "Move - Mike Koenig";
		CreditText(x, curY, printS);
		printS = "Loading - qubodup";
		CreditText(x, curY, printS);
		printS = "Fail - Riot Games";
		CreditText(x, curY, printS);
		printS = "Clear - DayDreamSound";
		CreditText(x, curY, printS);
		clock_t curtime, oldtime;
		oldtime = clock();
		while (true)
		{
			key = KeyController();
			curtime = clock();
			if (curtime - oldtime > 320 || key == (int)KEY::ESC)
			{
				break;
			}
		}
		SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
		system("cls");
	}
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	system("cls");
	Loading();
}

void CreditText(int x, int& curY, string printS)
{
	if (curY <= 29 && curY > 0)
	{
		GotoCur(x - printS.length() / 2, curY++);
		cout << printS;
	}
}

void PrintNum(int num, int posX, int posY,bool& isTwinkle, bool isSelect, int stage)
{
	if (isSelect)
	{
		if (isTwinkle)
		{
			if (stage == 0)
				SetColor((int)COLOR::RED, (int)COLOR::BLACK);
			else if (stage == 1)
				SetColor((int)COLOR::BLUE, (int)COLOR::BLACK);
			else if (stage == 2)
				SetColor((int)COLOR::YELLOW, (int)COLOR::BLACK);
			else if (stage == 3)
				SetColor((int)COLOR::GREEN, (int)COLOR::BLACK);
			else if (stage == 4)
				SetColor((int)COLOR::VIOLET, (int)COLOR::BLACK);
			else if (stage == 5)
				SetColor((int)COLOR::MINT, (int)COLOR::BLACK);

			isTwinkle = false;
		}
		else
			isTwinkle = true;
	}
	GotoCur(posX, posY++);
	cout << "■■■■■";
	GotoCur(posX, posY++);
	cout << "■      ■";
	GotoCur(posX, posY++);
	cout << "■  " << ((num < 10) ? "0" : "") << num << "  ■";
	GotoCur(posX, posY++);
	cout << "■      ■";
	GotoCur(posX, posY++);
	cout << "■■■■■";
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
}

void Loading()
{
	for (int i = 0; i < ScreenX; i += 5)
	{
		for (int j = 0; j < ScreenY; j += 5)
		{
			PrintLoading(j % 2 == 0, i, j);
		}
		system("cls");
	}

	for (int i = ScreenX; i > 0; i -= 5)
	{
		for (int j = 0; j < ScreenY; j += 5)
		{
			PrintLoading(j % 2 == 0, i, j);
		}

		system("cls");
	}
}

void PrintLoading(bool isLeft, int posX, int posY)
{
	if (posX < 15)
	{
		SetColor((int)COLOR::LIGHT_GRREN, (int)COLOR::BLACK);
	}
	else if (posX < 30)
	{
		SetColor((int)COLOR::BLUE, (int)COLOR::BLACK);
	}
	else if (posX < 45)
	{
		SetColor((int)COLOR::SKYBLUE, (int)COLOR::BLACK);
	}
	else if (posX < 60)
	{
		SetColor((int)COLOR::LIGHT_VIOLET, (int)COLOR::BLACK);
	}
	else if (posX < 75)
	{
		SetColor((int)COLOR::VIOLET, (int)COLOR::BLACK);
	}
	else if (posX < 90)
	{
		SetColor((int)COLOR::RED, (int)COLOR::BLACK);
	}
	else if (posX < 115)
	{
		SetColor((int)COLOR::LIGHT_RED, (int)COLOR::BLACK);
	}
	else
	{
		SetColor((int)COLOR::LIGHT_YELLOW, (int)COLOR::BLACK);
	}

	if (isLeft)
		GotoCur(posX, posY++);
	else
		GotoCur(ScreenX - posX, posY++);
	cout << "■■■■■■";

	if (isLeft)
		GotoCur(posX, posY++);
	else
		GotoCur(ScreenX - posX, posY++);
	cout << "■■■■■■";

	if (isLeft)
		GotoCur(posX, posY++);
	else
		GotoCur(ScreenX - posX, posY++);
	cout << "■■■■■■";

	if (isLeft)
		GotoCur(posX, posY++);
	else
		GotoCur(ScreenX - posX, posY++);
	cout << "■■■■■■";

	if (isLeft)
		GotoCur(posX, posY++);
	else
		GotoCur(ScreenX - posX, posY++);
	cout << "■■■■■■";
}

void PrintESC()
{
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	GotoCur(118, 28);
	cout << "Back ESC";
}