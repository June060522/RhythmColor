#include<Windows.h>
#include<mmsystem.h>
#include<Digitalv.h>
#pragma comment(lib, "winmm.lib") 

#include "SoundManager.h"
#include "define.h"
#include <ctime>
MCI_OPEN_PARMS openBgm;
MCI_PLAY_PARMS playBgm;
MCI_OPEN_PARMS openEffect;
MCI_PLAY_PARMS playEffect;
UINT Bgmid;
UINT Effectid;

SoundManager* SoundManager::m_pInst = nullptr;
SoundManager::SoundManager()
{

}
SoundManager::~SoundManager()
{
	SAFE_DELETE(m_pInst);
}

void SoundManager::PlayBgm(LPCWSTR s)
{
	mciSendCommand(Bgmid, MCI_CLOSE, 0, (DWORD)NULL);
	openBgm.lpstrElementName = s;
	openBgm.lpstrDeviceType = TEXT("mpegvideo");
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR)&openBgm);
	Bgmid = openBgm.wDeviceID;
	mciSendCommand(Bgmid, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD_PTR)&playBgm);
}

void SoundManager::PlayEffect(LPCWSTR s)
{
	openEffect.lpstrElementName = s;
	openEffect.lpstrDeviceType = TEXT("waveaudio");
	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD_PTR)&openEffect);
	Effectid = openEffect.wDeviceID;
	mciSendCommand(Effectid, MCI_PLAY, MCI_NOTIFY, (DWORD_PTR)&playEffect);
	clock_t curtime, oldtime;
	oldtime = clock();
	while (true)
	{
		curtime = clock();
		if (curtime - oldtime > 100)
		{
			break;
		}
	}
	mciSendCommand(Effectid, MCI_SEEK, MCI_SEEK_TO_START, (DWORD_PTR)&playEffect);
	mciSendCommand(Effectid, MCI_CLOSE, 0, (DWORD)NULL);
}
