#include <iostream>
#include <fstream>
#include "Stage.h"
#include "define.h"

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
		readFile.getline(m_cStage[i], MAP_X + 1);
		for (int j = 0; j < MAP_X; j++)
		{
			if (m_cStage[i][j] == (char)STAGE_TYPE::START)
			{
				m_tStart.x = j;
				m_tStart.y = i;
			}
			else if (m_cStage[i][j] == (char)STAGE_TYPE::END)
			{
				m_tEnd.x = j;
				m_tEnd.y = i;
			}
		}
	}
	readFile.close();
}

void Stage::Render()
{
	system("cls");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (m_cStage[i][j] == (char)STAGE_TYPE::REDWALL)
				cout << "��";
			else if (m_cStage[i][j] == (char)STAGE_TYPE::BLUEWALL)
				cout << "��";
			else if (m_cStage[i][j] == (char)STAGE_TYPE::YELLOWWALL)
				cout << "��";
			else if (m_cStage[i][j] == (char)STAGE_TYPE::GREENWALL)
				cout << "��";
			else if (m_cStage[i][j] == (char)STAGE_TYPE::VIOLETWALL)
				cout << "��";
			else if (m_cStage[i][j] == (char)STAGE_TYPE::MINTWALL)
				cout << "��";
			else if (m_cStage[i][j] == (char)STAGE_TYPE::ROAD)
				cout << "��";
			else if (m_cStage[i][j] == (char)STAGE_TYPE::START)
				cout << "0";
			else if (m_cStage[i][j] == (char)STAGE_TYPE::END)
				cout << "��";
			else if (m_cStage[i][j] == (char)STAGE_TYPE::TELEPORT)
				cout << "��";
			else if (m_cStage[i][j] == (char)STAGE_TYPE::CHANGERED)
				cout << "��";
			else if (m_cStage[i][j] == (char)STAGE_TYPE::CHANGEBLUE)
				cout << "��";
			else if (m_cStage[i][j] == (char)STAGE_TYPE::CHANGEYELLOW)
				cout << "��";
			else if (m_cStage[i][j] == (char)STAGE_TYPE::CHANGEGREEN)
				cout << "��";
			else if (m_cStage[i][j] == (char)STAGE_TYPE::CHANGEVIOLET)
				cout << "��";
			else if (m_cStage[i][j] == (char)STAGE_TYPE::CHANGEMINT)
				cout << "��";
			else if (m_cStage[i][j] == (char)STAGE_TYPE::BLUEWALL)
				cout << "��";
		}
		cout << endl;
	}
}