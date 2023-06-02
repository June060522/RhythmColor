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

void PrintTitleSelectMode();

void PressSpace();

int PrintMenu();
