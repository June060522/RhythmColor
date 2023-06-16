#pragma once
const int HORIZON = 50;
const int VERTICAL = 25;

enum Direction
{
	left = 1,
	right = 2,
	up = 3,
	down = 4
};

typedef struct tagpos
{
	int x;
	int y;
}POS, * PPOS;

typedef struct _tagplayer
{
	POS tpos;
	POS tNewPos;
	int iColor;
	int iCurDir;
}PLAYER, * PPLAYER;

void Update(PPLAYER& _pPlayer);