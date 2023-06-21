#include <iostream>
#include <fstream>
#include "Stage.h"
#include "define.h"
#include "console.h"
#include <fcntl.h>
#include <io.h>
#include "StartScene.h"

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

void Stage::Render(PPLAYER pPlayer)
{
	system("cls");
	for (int i = 0; i < 25; i++)
	{
		GotoCur(16, i + 2);
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
				SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
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

	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	GotoCur(118, 28);
	cout << "Back ESC";
}

bool Stage::Event(PPLAYER pPlayer, bool& isClear)
{
	if (pPlayer->iCurDir == (int)Direction::left)
	{
		pPlayer->tNewPos.x = pPlayer->tpos.x - 1;
		pPlayer->tNewPos.y = pPlayer->tpos.y;
	}
	else if (pPlayer->iCurDir == (int)Direction::right)
	{
		pPlayer->tNewPos.x = pPlayer->tpos.x + 1;
		pPlayer->tNewPos.y = pPlayer->tpos.y;
	}
	else if (pPlayer->iCurDir == (int)Direction::up)
	{
		pPlayer->tNewPos.x = pPlayer->tpos.x;
		pPlayer->tNewPos.y = pPlayer->tpos.y - 1;
	}
	else if (pPlayer->iCurDir == (int)Direction::down)
	{
		pPlayer->tNewPos.x = pPlayer->tpos.x;
		pPlayer->tNewPos.y = pPlayer->tpos.y + 1;
	}

	if (m_cStage[pPlayer->tNewPos.y][pPlayer->tNewPos.x] == (char)STAGE_TYPE::ROAD)
	{
		swap(m_cStage[pPlayer->tpos.y][pPlayer->tpos.x], m_cStage[pPlayer->tNewPos.y][pPlayer->tNewPos.x]);
		pPlayer->tpos = pPlayer->tNewPos;
		return true;
	}
	else if (m_cStage[pPlayer->tNewPos.y][pPlayer->tNewPos.x] == (char)STAGE_TYPE::END)
		isClear = true;
	return false;
}

void Stage::Update(PPLAYER _pPlayer)
{
	int input = KeyController();

	if (input == (int)KEY::A && !(m_cStage[_pPlayer->tpos.y][_pPlayer->tpos.x - 1] >= (char)STAGE_TYPE::REDWALL &&
		m_cStage[_pPlayer->tpos.y][_pPlayer->tpos.x - 1] <= (char)STAGE_TYPE::MINTWALL))
	{
		_pPlayer->iCurDir = (int)Direction::left;
	}
	else if (input == (int)KEY::D && !(m_cStage[_pPlayer->tpos.y][_pPlayer->tpos.x + 1] >= (char)STAGE_TYPE::REDWALL &&
		m_cStage[_pPlayer->tpos.y][_pPlayer->tpos.x + 1] <= (char)STAGE_TYPE::MINTWALL))
	{
		_pPlayer->iCurDir = (int)Direction::right;
	}
	else if (input == (int)KEY::S && !(m_cStage[_pPlayer->tpos.y + 1][_pPlayer->tpos.x] >= (char)STAGE_TYPE::REDWALL &&
		m_cStage[_pPlayer->tpos.y + 1][_pPlayer->tpos.x] <= (char)STAGE_TYPE::MINTWALL))
	{
		_pPlayer->iCurDir = (int)Direction::down;
	}
	else if (input == (int)KEY::W && !(m_cStage[_pPlayer->tpos.y - 1][_pPlayer->tpos.x] >= (char)STAGE_TYPE::REDWALL &&
		m_cStage[_pPlayer->tpos.y - 1][_pPlayer->tpos.x] <= (char)STAGE_TYPE::MINTWALL))
	{
		_pPlayer->iCurDir = (int)Direction::up;
	}

}

void Stage::PlayerRender(PPLAYER pPlayer)
{
	SetColor((int)pPlayer->iColor, (int)COLOR::BLACK);
	int x = pPlayer->tpos.x + 8;
	int y = pPlayer->tpos.y + 2;
	x *= 2;
	GotoCur(x, y);
	cout << "ме";
	if (pPlayer->iCurDir == (int)Direction::down)
	{
		y--;
	}
	else if (pPlayer->iCurDir == (int)Direction::right)
	{
		x -= 2;
	}
	else if (pPlayer->iCurDir == (int)Direction::left)
	{
		x += 2;
	}
	else if (pPlayer->iCurDir == (int)Direction::up)
	{
		y++;
	}
	GotoCur(x + 2, y);
	cout << "\b\b  ";
}
