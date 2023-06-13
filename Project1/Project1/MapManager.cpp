#include "MapManager.h"
#include "Stage.h"
#include "console.h"
#include <iostream>
#include <string>
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
    std::string save;
    char* pFileName[30];
    for (int i = 1; i <= 30; i++)
    {
        save = "Stage";
        save += (i / 10) + '0';
        save += (i % 10) + '0';
        /*int deg = 1;
        if (i >= 10)
            deg = 2;
        char* c = new char[deg];
        _itoa_s(i, c,1, deg);
        save += c;
        delete[] c;*/
        save += ".txt";
        pFileName[i - 1] = (char*)save.c_str();
    }
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
    m_iCurstage = iCurStage;
    while (true)
    {
        GotoCur(0, 0);
        m_pStage[m_iCurstage]->Render();
    }
}
