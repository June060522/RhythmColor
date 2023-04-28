#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include "console.h"
#include "StartScene.h"

using namespace std;

int main()
{
	Init();
	
	PrintTitle();
	PressSpace();
	while (true)
	{
		PrintTitle();
		int select = PrintMenu();
	}
}