#pragma once

#include <Windows.h>

#define ARRAY_LEN 100000
#define INPUTLEN 128
#define WORDY "%127s"
// define a 31 byte string
#define LONG_STR "This is my long secret string."
CHAR un[INPUTLEN];
CHAR nd[INPUTLEN];

DWORD Stage1(VOID);
DWORD Stage2(PCHAR data);
DWORD Stage3(DWORD data);
DWORD Stage4(PCHAR data);
DWORD Stage5(DWORD data_len);

/* end of file */