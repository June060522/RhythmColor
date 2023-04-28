#pragma once
#include <Windows.h>

const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

void Init();

void GotoCur(int,int);