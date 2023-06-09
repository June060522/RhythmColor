#pragma once
enum class KEY
{
	UP, DOWN, Space
};

enum class Mode
{
	Play, Option, Credits, Exit
};

void PrintTitleAndSpace();

void PressSpace();

int PrintMenu();

void PrintStageSelect();

void PrintCredit();

void PrintOption();