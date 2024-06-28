#include <Windows.h>
#include <stdio.h>

#include "stages.h"


DWORD Stage1(VOID)
{
	BOOL bRet = FALSE;
	CHAR input[INPUTLEN] = { 0 };
	scanf_s(WORDY, input, INPUTLEN);

	DWORD dwRes = 0;
	dwRes = strcmp(input, "pavel");

	if (0 == dwRes)
	{
		bRet = TRUE;
	}
	return bRet;
}

DWORD Stage2(PCHAR data)
{
	BOOL bRet = FALSE;
	CHAR un[INPUTLEN] = { 0 };
	scanf_s(WORDY, data, INPUTLEN);
	DWORD res = GetEnvironmentVariableA("USERNAME", un, INPUTLEN);
	if (0 == strcmp(un, data))
	{
		bRet = TRUE;
	}
	return bRet;
}
