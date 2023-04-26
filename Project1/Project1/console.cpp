#include "console.h"

void FullScreen()
{
    SetConsoleDisplayMode(hOut , CONSOLE_FULLSCREEN_MODE, 0);
}