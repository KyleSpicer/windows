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
} // Stage1

DWORD Stage2(PCHAR data)
{
	BOOL bRet = FALSE;
	INT data_len = scanf_s(WORDY, data, INPUTLEN - 1);
	DWORD res = GetEnvironmentVariableA("USERNAME", un, INPUTLEN);
	if (0 == strcmp(un, data))
	{
		memcpy(un, data, data_len);
		bRet = TRUE;
	}
	return bRet;
} // Stage2

DWORD Stage3(DWORD data_len)
{
	BOOL bRet = FALSE;
	scanf_s(WORDY, nd, INPUTLEN - 1);

	DWORD dwLen = strlen(nd);
	DWORD dwVal = atoi(nd);

	if (dwVal == (dwLen + data_len))
	{
		bRet = TRUE;
	}
	return bRet;
} // Stage3

/* end of file */