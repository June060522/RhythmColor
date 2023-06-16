#include "Core.h"
#include "console.h"
#include "StartScene.h"
#include "MapManager.h"
#include "SoundManager.h"
Core* Core::m_pInst = nullptr;

Core::Core()
{

}

Core::~Core()
{
}

bool Core::Init()
{
	if (!MapManager::GetInst()->Init())
		return false;
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
	return true;
}

void Core::Run()
{
	int iStage = 0;
	SoundManager::GetInst()->PlayBgm(TEXT("Sound\\BackGround.mp3"));
	while (true)
	{
		system("cls");
		PressSpace();
		int select = PrintMenu();

		system("cls");
		if (select == (int)Mode::Play)
		{
			iStage = PrintStageSelect();
			if (iStage == -1)
				continue;
			else
				MapManager::GetInst()->Run(iStage-1);
		}
		else if (select == (int)Mode::Credits)
		{
			PrintCredit();
		}
		else if (select == (int)Mode::Exit)
		{
			SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
			break;
		}
	}
}
