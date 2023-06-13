#pragma once
#include "define.h"
class Core
{
private:
	Core();
	~Core();
private:
	static Core* m_pInst;
public:
	static Core* GetInst()
	{
		if (nullptr == m_pInst)
			m_pInst = new Core;
		return m_pInst;
	}

	static void DestroyInst()
	{
		SAFE_DELETE(m_pInst);
	}
public:
	bool Init();
	void Run();
};