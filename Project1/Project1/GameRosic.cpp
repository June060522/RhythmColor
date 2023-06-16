#include <iostream>
#include "GameRosic.h"
#include "StartScene.h"


void Update(PPLAYER& _pPlayer)
{
	int input = KeyController();

	if (input == (int)KEY::A)
	{
		_pPlayer->iCurDir = (int)Direction::left;
	}
	else if (input == (int)KEY::D)
	{
		_pPlayer->iCurDir = (int)Direction::right;
	}
	else if (input == (int)KEY::S)
	{
		_pPlayer->iCurDir = (int)Direction::down;
	}
	else if (input == (int)KEY::W)
	{
		_pPlayer->iCurDir = (int)Direction::up;
	}

}
