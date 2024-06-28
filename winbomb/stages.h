#pragma once

#include <Windows.h>

#define ARRAY_LEN 100000
#define INPUTLEN 128
#define EXPECTED_ARGC 4
#define WORDY "%127s"

#define LONG_STR "This is my long secret string."
#define EXPECTED_ARG1 "open"
#define EXPECTED_ARG2 "sesame"

CHAR un[INPUTLEN];
CHAR nd[INPUTLEN];

DWORD Stage1(VOID);
DWORD Stage2(PCHAR data);
DWORD Stage3(SIZE_T data);
DWORD Stage4(PCHAR data);
DWORD Stage5(SIZE_T data_len);
DWORD Stage6(INT argc, PCHAR argv[]);

/* end of file */