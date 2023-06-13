#pragma once
#include <Windows.h>
#define SAFE_DELETE(p) if(p) {delete p; p=nullptr;}
const int MAP_X = 50;
const int MAP_Y = 30;
enum class STAGE_TYPE
{
	REDWALL = '0',
	BLUEWALL = '1',
	YELLOWWALL = '2',
	GREENWALL = '3',
	VIOLETWALL = '4',
	MINTWALL = '5',
	ROAD = '6',
	START = '7',
	END = '8',
	TELEPORT = 'T',
	CHANGERED = 'R',
	CHANGEBLUE = 'B',
	CHANGEYELLOW= 'Y',
	CHANGEGREEN = 'G',
	CHANGEVIOLET = 'V',
	CHANGEMINT = 'M',
};