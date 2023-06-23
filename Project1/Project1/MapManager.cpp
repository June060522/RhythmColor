#include "GameRogic.h"
#include "MapManager.h"
#include "SoundManager.h"
#include "Stage.h"
#include "console.h"
#include <string>
#include <ctime>
MapManager* MapManager::m_pInst = nullptr;

MapManager::MapManager()
{
	for (int i = 0; i < 30; i++)
		m_pStage[i] = nullptr;
}

MapManager::~MapManager()
{
	for (int i = 0; i < 30; i++)
		SAFE_DELETE(m_pStage[i]);
}

bool MapManager::Init()
{
	char* pFileName[30] = { (char*)"Stage01.txt", (char*)"Stage02.txt" ,(char*)"Stage03.txt" , (char*)"Stage04.txt" , (char*)"Stage05.txt" ,
	(char*)"Stage06.txt" , (char*)"Stage07.txt" , (char*)"Stage08.txt" , (char*)"Stage09.txt" , (char*)"Stage10.txt" , (char*)"Stage11.txt" , (char*)"Stage12.txt" ,
	(char*)"Stage13.txt" , (char*)"Stage14.txt" , (char*)"Stage15.txt" , (char*)"Stage16.txt" , (char*)"Stage17.txt" , (char*)"Stage18.txt" , (char*)"Stage19.txt" ,
	(char*)"Stage20.txt" , (char*)"Stage21.txt" , (char*)"Stage22.txt" , (char*)"Stage23.txt" , (char*)"Stage24.txt" , (char*)"Stage25.txt" , (char*)"Stage26.txt" ,
	(char*)"Stage27.txt" , (char*)"Stage28.txt" , (char*)"Stage29.txt" , (char*)"Stage30.txt" , };
	for (int i = 0; i < 30; i++)
	{
		m_pStage[i] = new Stage;
		if (!(m_pStage[i]->Init(pFileName[i])))
			return false;
	}
	return true;
}

void MapManager::Run(int iCurStage)
{
	Init();
	bool isClear = false;
	PLAYER tPlayer = {};
	POS tStartPos = {};
	m_iCurstage = iCurStage;
	float time = 0;//여기가 비트
	clock_t curtime, oldtime;
	Reset(iCurStage, time, tPlayer, tStartPos);
	curtime = clock();
	oldtime = clock();
	bool isdelete = false;
	while (!isClear)
	{
		while (curtime - oldtime < time)
		{
			m_pStage[m_iCurstage]->Update(&tPlayer, isClear);
			curtime = clock();
		}

		oldtime = clock();

		while (m_pStage[m_iCurstage]->Event(&tPlayer, isClear,isdelete))
		{
			m_pStage[m_iCurstage]->PlayerRender(&tPlayer,isdelete);
			isdelete = false;
		}

		if (isClear)
			break;

		if (!m_pStage[m_iCurstage]->CheckDie(&tPlayer))
		{
			SoundManager::GetInst()->PlayEffect(TEXT("Sound\\Die.wav"));
			Init();
			Reset(iCurStage, time, tPlayer, tStartPos);
			continue;
		}



		if (tPlayer.iCurDir == (int)Direction::down)
		{
			m_pStage[m_iCurstage]->PrintDirection(Direction::up);
			tPlayer.iCurDir = (int)Direction::up;
		}
		else if (tPlayer.iCurDir == (int)Direction::up)
		{
			m_pStage[m_iCurstage]->PrintDirection(Direction::down);
			tPlayer.iCurDir = (int)Direction::down;
		}
		else if (tPlayer.iCurDir == (int)Direction::left)
		{
			m_pStage[m_iCurstage]->PrintDirection(Direction::right);
			tPlayer.iCurDir = (int)Direction::right;
		}
		else if (tPlayer.iCurDir == (int)Direction::right)
		{
			m_pStage[m_iCurstage]->PrintDirection(Direction::left);
			tPlayer.iCurDir = (int)Direction::left;
		}
	}

	SoundManager::GetInst()->PlayBgm(TEXT("Sound\\BackGround.mp3"));
}

void MapManager::Reset(int& iCurStage, float& time, PLAYER& pPlayer, POS& pStartPos)
{
	if (iCurStage < 5)
	{
		SoundManager::GetInst()->PlayBgm(TEXT("Sound\\Chapter1.mp3"));
		time = 600;
	}
	else if (iCurStage < 10)
	{
		SoundManager::GetInst()->PlayBgm(TEXT("Sound\\Chapter2.mp3"));
		time = 600;
	}
	else if (iCurStage < 15)
	{
		SoundManager::GetInst()->PlayBgm(TEXT("Sound\\Chapter3.mp3"));
		time = 550;
	}
	else if (iCurStage < 20)
	{
		SoundManager::GetInst()->PlayBgm(TEXT("Sound\\Chapter4.mp3"));
		time = 500;
	}
	else if (iCurStage < 25)
	{
		SoundManager::GetInst()->PlayBgm(TEXT("Sound\\Chapter5.mp3"));
		time = 600;
	}
	else
	{
		SoundManager::GetInst()->PlayBgm(TEXT("Sound\\Chapter6.mp3"));
		time = 600;
	}
	m_pStage[m_iCurstage]->Render(&pPlayer, &pStartPos);
}
