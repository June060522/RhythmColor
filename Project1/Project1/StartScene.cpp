#include <iostream>
#include "StartScene.h"
#include "console.h"
#include <io.h>
#include <fcntl.h>

using namespace std;

int mode;

int KeyController()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		return (int)KEY::UP;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		return (int)KEY::DOWN;
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		return (int)KEY::Space;

	return -1;
}

bool InputSpace(const wchar_t* text)
{
	mode = _setmode(_fileno(stdout), _O_U16TEXT);
	clock_t curtime, oldtime;
	oldtime = clock();
	SetColor(rand() % 15 + 1, (int)COLOR::BLACK);
	wcout << text << endl;
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

void PrintSpace(string sPrint)
{
	GotoCur(60, 20);
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
	int x = 22;
	int y = 5;
	mode = _setmode(_fileno(stdout), _O_U16TEXT);
	while (true)
	{
		x = 22;
		y = 5;


		PrintSpace("Press 'Space' to Start");
		GotoCur(x, y++);
		if (InputSpace(L"██████╗ ██╗  ██╗██╗   ██╗████████╗██╗  ██╗███╗   ███╗     ██████╗ ██████╗ ██╗      ██████╗ ██████╗ "))
			return;


		PrintSpace("                      ");
		GotoCur(x, y++);
		if (InputSpace(L"██╔══██╗██║  ██║╚██╗ ██╔╝╚══██╔══╝██║  ██║████╗ ████║    ██╔════╝██╔═══██╗██║     ██╔═══██╗██╔══██╗"))
			return;


		PrintSpace("Press 'Space' to Start");
		GotoCur(x, y++);
		if (InputSpace(L"██████╔╝███████║ ╚████╔╝    ██║   ███████║██╔████╔██║    ██║     ██║   ██║██║     ██║   ██║██████╔╝"))
			return;


		PrintSpace("                      ");
		GotoCur(x, y++);
		if (InputSpace(L"██╔══██╗██╔══██║  ╚██╔╝     ██║   ██╔══██║██║╚██╔╝██║    ██║     ██║   ██║██║     ██║   ██║██╔══██╗"))
			return;


		PrintSpace("Press 'Space' to Start");
		GotoCur(x, y++);
		if (InputSpace(L"██║  ██║██║  ██║   ██║      ██║   ██║  ██║██║ ╚═╝ ██║    ╚██████╗╚██████╔╝███████╗╚██████╔╝██║  ██║"))
			return;


		PrintSpace("                      ");
		GotoCur(x, y++);
		if (InputSpace(L"╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝      ╚═╝   ╚═╝  ╚═╝╚═╝     ╚═╝     ╚═════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝  ╚═╝"))
			return;
	}
}

void PressSpace()
{
	int x = 60;
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
	int x = 50;
	int y = 20;
	GotoCur(x, y++);
	cout << "Play";
	GotoCur(x, y++);
	cout << "Options";
	GotoCur(x, y++);
	cout << "Credits";
	GotoCur(x, y++);
	cout << "Exit";
	x = 47;
	y = 20;
	GotoCur(x, y);
	while (true)
	{
		clock_t curtime, oldtime;
		oldtime = clock();
		while (true)
		{
			key = KeyController();
			curtime = clock();
			if (curtime - oldtime > 99)
			{
				break;
			}
		}

		if (key == (int)KEY::UP)
			y--;
		else if (key == (int)KEY::DOWN)
			y++;
		else if (key == (int)KEY::Space)
			return y - 20;

		if (y > 23)
			y = 23;
		else if (y < 20)
			y = 20;

		cout << "\b\b";
		cout << "  ";
		GotoCur(x, y);
		cout << "▷";
	}
	return -1;
}

void PrintStageSelect()
{

}

void PrintCredit()
{
	while (true)
	{
		cout << "Developer And Level Designer" << endl;
		cout << "June" << endl << endl;

		cout << "Cooperator" << endl;
		cout << "JunYoung Teacher" << endl;

		cout << "Reference Game" << endl;
		cout << "COLORFUL RECOLOR" << endl;

		cout << "Music Composer" << endl;
		cout << "Etc" << endl;
	}
}

void PrintOption()
{

}