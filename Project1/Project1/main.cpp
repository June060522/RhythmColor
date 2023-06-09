#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include "console.h"
#include "StartScene.h"

using namespace std;

int main()
{
	Init();

	while (true)
	{
		system("cls");
		PressSpace();
		int select = PrintMenu();
		
		system("cls");
		if (select == (int)Mode::Play)
		{
			PrintStageSelect();
		}
		else if (select == (int)Mode::Option)
		{
			PrintOption();
		}
		else if (select == (int)Mode::Credits)
		{
			PrintCredit();
		}
		else if (select == (int)Mode::Exit)
		{
			break;
		}
	}
}