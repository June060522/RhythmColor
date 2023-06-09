#pragma once
#include "define.h"
#include "GameRogic.h"
class Stage
{
public:
	Stage();
	~Stage();
private:
	char m_cStage[MAP_Y][MAP_X];
	POINT m_tStart;
	POINT m_tEnd;
public:
	POINT GetStart() { return m_tStart; }
	POINT GetEnd() { return m_tEnd; }
	char GetMap(int x, int y) { return m_cStage[y][x]; }
public:
	bool Init(const char* _pFilename);
	void Render(PPLAYER pPlayer, PPOS pStartPos);
	bool Event(PPLAYER pPlayer, bool& isClear, bool& isdelete);
	void PlayerRender(PPLAYER pPlayer, bool isdelete);
	void Update(PPLAYER pPlayer, bool& isClear);

public:
	void PrintDirection(Direction dir);
	bool CheckDie(PPLAYER pPlayer);
};