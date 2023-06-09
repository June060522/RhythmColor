#pragma once
#include "GameRogic.h"
#include "define.h"
class Stage;
class MapManager
{
private:
	MapManager();
	~MapManager();
private:
	static MapManager* m_pInst;
private:
	Stage* m_pStage[30];
	int m_iCurstage;
public:
	Stage* GetStage() { return m_pStage[m_iCurstage]; }
public:
	static MapManager* GetInst()
	{
		if (m_pInst == nullptr)
			m_pInst = new MapManager;
		return m_pInst;
	}
	static void DestroyInst()
	{
		SAFE_DELETE(m_pInst);
	}
public:
	bool Init();
	void Run(int iCurStage);
	void Reset(int& iCurStage, float& time, PLAYER& tPlayer, POS& tStartPos);
};