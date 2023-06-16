#include <iostream>
#include <fstream>
#include "Stage.h"
#include "define.h"
#include "console.h"

using namespace std;

Stage::Stage()
	: m_tStart{}
	, m_tEnd{}
	, m_cStage{}
{

}

Stage::~Stage()
{

}

bool Stage::Init(const char* _pFilename)
{
	ifstream readFile;
	if (readFile.is_open())
		return false;
	readFile.open(_pFilename);
	for (int i = 0; i < MAP_Y; i++)
	{
		readFile.clear();
		readFile.getline(m_cStage[i], MAP_X + 1);
	}
	readFile.close();
	return true;
}

void Stage::Render( PPLAYER& pPlayer)
{
	system("cls");
	for (int i = 0; i < 25; i++)
	{
		GotoCur(16,i + 2);
		for (int j = 0; j < 50; j++)
		{
			if (m_cStage[i][j] == (char)STAGE_TYPE::REDWALL)
			{
				SetColor((int)COLOR::RED, (int)COLOR::BLACK);
				cout << "бс";
			}
			else if (m_cStage[i][j] == (char)STAGE_TYPE::BLUEWALL)
			{
				SetColor((int)COLOR::BLUE, (int)COLOR::BLACK);
				cout << "бс";
			}
			else if (m_cStage[i][j] == (char)STAGE_TYPE::YELLOWWALL)
			{
				SetColor((int)COLOR::YELLOW, (int)COLOR::BLACK);
				cout << "бс";
			}
			else if (m_cStage[i][j] == (char)STAGE_TYPE::GREENWALL)
			{
				SetColor((int)COLOR::GREEN, (int)COLOR::BLACK);
				cout << "бс";
			}
			else if (m_cStage[i][j] == (char)STAGE_TYPE::VIOLETWALL)
			{
				SetColor((int)COLOR::VIOLET, (int)COLOR::BLACK);
				cout << "бс";
			}
			else if (m_cStage[i][j] == (char)STAGE_TYPE::MINTWALL)
			{
				SetColor((int)COLOR::MINT, (int)COLOR::BLACK);
				cout << "бс";
			}
			else if (m_cStage[i][j] == (char)STAGE_TYPE::ROAD)
			{
				cout << "  ";
			}
			else if (m_cStage[i][j] == (char)STAGE_TYPE::START)
			{
				cout << "ме";
				m_tStart.x = j;
				m_tStart.y = i;
			}
			else if (m_cStage[i][j] == (char)STAGE_TYPE::END)
			{
				cout << "б┌";
				m_tEnd.x = j;
				m_tEnd.y = i;
			}
			else if (m_cStage[i][j] == (char)STAGE_TYPE::TELEPORT)
			{
				cout << "в═";
			}
			else if (m_cStage[i][j] == (char)STAGE_TYPE::CHANGERED)
			{
				SetColor((int)COLOR::RED, (int)COLOR::BLACK);
				cout << "в├";
			}
			else if (m_cStage[i][j] == (char)STAGE_TYPE::CHANGEBLUE)
			{
				SetColor((int)COLOR::BLUE, (int)COLOR::BLACK);
				cout << "в├";
			}
			else if (m_cStage[i][j] == (char)STAGE_TYPE::CHANGEYELLOW)
			{
				SetColor((int)COLOR::YELLOW, (int)COLOR::BLACK);
				cout << "в├";
			}
			else if (m_cStage[i][j] == (char)STAGE_TYPE::CHANGEGREEN)
			{
				SetColor((int)COLOR::GREEN, (int)COLOR::BLACK);
				cout << "в├";
			}
			else if (m_cStage[i][j] == (char)STAGE_TYPE::CHANGEVIOLET)
			{
				SetColor((int)COLOR::VIOLET, (int)COLOR::BLACK);
				cout << "в├";
			}
			else if (m_cStage[i][j] == (char)STAGE_TYPE::CHANGEMINT)
			{
				SetColor((int)COLOR::MINT, (int)COLOR::BLACK);
				cout << "в├";
			}
		}
		cout << endl;
	}
	//pPlayer->tpos.x = m_tStart.x;
	//pPlayer->tpos.y = m_tStart.y;
}

void Stage::Event(PPLAYER& pPlayer)
{

}