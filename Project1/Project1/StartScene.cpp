#include <iostream>
#include "StartScene.h"
#include "console.h"
#include <io.h>
#include <fcntl.h>

using namespace std;

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

void PrintTitle()
{
	int x = 22;
	int y = 5;
	int mode = _setmode(_fileno(stdout), _O_U16TEXT);
	GotoCur(x, y++);
	wcout << L"██████╗ ██╗  ██╗██╗   ██╗████████╗██╗  ██╗███╗   ███╗     ██████╗ ██████╗ ██╗      ██████╗ ██████╗ " << endl;
	GotoCur(x, y++);
	wcout << L"██╔══██╗██║  ██║╚██╗ ██╔╝╚══██╔══╝██║  ██║████╗ ████║    ██╔════╝██╔═══██╗██║     ██╔═══██╗██╔══██╗" << endl;
	GotoCur(x, y++);
	wcout << L"██████╔╝███████║ ╚████╔╝    ██║   ███████║██╔████╔██║    ██║     ██║   ██║██║     ██║   ██║██████╔╝" << endl;
	GotoCur(x, y++);
	wcout << L"██╔══██╗██╔══██║  ╚██╔╝     ██║   ██╔══██║██║╚██╔╝██║    ██║     ██║   ██║██║     ██║   ██║██╔══██╗" << endl;
	GotoCur(x, y++);
	wcout << L"██║  ██║██║  ██║   ██║      ██║   ██║  ██║██║ ╚═╝ ██║    ╚██████╗╚██████╔╝███████╗╚██████╔╝██║  ██║" << endl;
	GotoCur(x, y);
	wcout << L"╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝      ╚═╝   ╚═╝  ╚═╝╚═╝     ╚═╝     ╚═════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝  ╚═╝" << endl;
	mode = _setmode(_fileno(stdout), mode);


}
void PressSpace()
{
	int x = 60;
	int y = 20;
	while (KeyController() != (int)KEY::Space)
	{
		GotoCur(x, y);
		cout << "Press 'Space' to Start";
		Sleep(130);
		if (KeyController() == (int)KEY::Space)
			break;
		GotoCur(x, y);
		cout << "                      ";
		Sleep(130);
	}

}
int PrintMenu()
{
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
	while (true)
	{

	}
	return -1;
}
