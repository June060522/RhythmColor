#pragma once
#include"define.h";

class SoundManager
{
private:
	SoundManager();
	~SoundManager();
private:
	static SoundManager* m_pInst;
public:
	static SoundManager* GetInst()
	{
		if (m_pInst == nullptr)
			m_pInst = new SoundManager;
		return m_pInst;
	}
	static void DestroyInst()
	{
		SAFE_DELETE(m_pInst);
	}

public:
	void PlayBgm(LPCWSTR s);
	void PlayEffect(LPCWSTR s);
};