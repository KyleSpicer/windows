#pragma once

#include <Windows.h>

#define INPUTLEN 128
#define WORDY "%127s"
CHAR un[INPUTLEN];
CHAR nd[INPUTLEN];

DWORD Stage1(VOID);
DWORD Stage2(PCHAR data);
DWORD Stage3(DWORD data);

/* end of file */
