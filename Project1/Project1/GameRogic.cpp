#include <iostream>
#include "GameRogic.h"
#include "StartScene.h"
#include "console.h"


void Ini(PPLAYER _pPlayer,PPOS _pStartPos, PPOS _pEndpos)
{
	_pStartPos->x = 2;
	_pStartPos->y = 23;
	_pEndpos->x = 14;
	_pEndpos->y = 7;
	PLAYER tSetplayer = { *_pStartPos,{},(int)COLOR::RED,(int)Direction::left};
	*_pPlayer = tSetplayer;
}
