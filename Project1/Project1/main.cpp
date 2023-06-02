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
		PressSpace();
		int select = PrintMenu();
		
		if (select == (int)Mode::Play)
		{

		}
		else if (select == (int)Mode::Option)
		{

		}
		else if (select == (int)Mode::Credits)
		{

		}
		else if (select == (int)Mode::Exit)
		{
			break;
		}
	}
}