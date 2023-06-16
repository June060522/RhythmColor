#include "MapManager.h"
#include "Stage.h"
#include "console.h"
#include "GameRosic.h"
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
    PPLAYER tPlayer;
    m_iCurstage = iCurStage;
    float time = 90;
    clock_t curtime, oldtime;
    while (true)
    {
        curtime = clock();
        oldtime = clock();

        while (curtime - oldtime < time)
		{
            Update(tPlayer);
            curtime = clock();
		}
        m_pStage[m_iCurstage]->Render(tPlayer);
    }
}
