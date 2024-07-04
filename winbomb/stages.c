#include <Windows.h>
#include <stdio.h>

#include "stages.h"

DWORD Stage1(VOID)
{
	BOOL bRet = EXIT_FAILURE;
	CHAR input[INPUTLEN] = { 0 };
	scanf_s(WORDY, input, INPUTLEN);

	DWORD dwRes = 0;
	dwRes = strcmp(input, "pavel");

	if (0 == dwRes)
	{
		bRet = EXIT_SUCCESS;
	}
	return bRet;
} // Stage1

DWORD Stage2(PCHAR data)
{
	BOOL bRet = EXIT_FAILURE;
	INT data_len = scanf_s(WORDY, data, INPUTLEN - 1);
	DWORD res = GetEnvironmentVariableA("USERNAME", un, INPUTLEN);
	if (0 == strcmp(un, data))
	{
		memcpy(un, data, data_len);
		bRet = EXIT_SUCCESS;
	}
	return bRet;
} // Stage2

DWORD Stage3(SIZE_T data_len)
{
	BOOL bRet = EXIT_FAILURE;
	scanf_s(WORDY, nd, INPUTLEN - 1);

	SIZE_T dwLen = strlen(nd);
	DWORD dwVal = atoi(nd);

	if (dwVal == (DWORD)(dwLen + data_len))
	{
		bRet = EXIT_SUCCESS;
	}
	return bRet;
} // Stage3

DWORD Stage4(PCHAR data)
{
	BOOL bRet = EXIT_FAILURE;
	scanf_s(WORDY, nd, INPUTLEN - 1);
	DWORD i = atoi(nd);
	DWORD p = GetCurrentProcessId();

	if (p == i)
	{
		bRet = EXIT_SUCCESS;
	}
	return bRet;
} // Stage4

DWORD Stage5(SIZE_T data_len, INT * ptr)
{
	BOOL bRet = EXIT_FAILURE;
	CHAR input[INPUTLEN] = { 0 };
	PCHAR* arr = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, ARRAY_LEN * sizeof(CHAR*));
	if (!arr)
		return EXIT_FAILURE;

	for (INT i = 0; i < ARRAY_LEN; ++i)
	{
		arr[i] = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, 32);
		if (!arr[i])
			return EXIT_FAILURE;

		snprintf(arr[i], 31, "%s", LONG_STR);
		for (INT j = 0; j < 31; ++j)
		{
			arr[i][j] ^= 0x42 + i + j % 8;
			if (arr[i][j] < 060 || (arr[i][j] > 071 && arr[i][j] < 65) || (arr[i][j] > 0x5A && arr[i][j] < 0x61) || arr[i][j] > 'z')
			{
				arr[i][j] = arr[i][j] % data_len ? '0' : 'd';
			}
		}
	}

	INT idx = MAXINT % ARRAY_LEN;
	for (INT i = 0; i < ARRAY_LEN; ++i)
	{
		if (i != idx)
		{
			HeapFree(GetProcessHeap(), 0, arr[i]);
		}
	}
	scanf_s(WORDY, input, INPUTLEN);

	if (0 == strcmp(input, arr[idx])) {
		*ptr = idx;
		bRet = EXIT_SUCCESS;
	}
	HeapFree(GetProcessHeap(), 0, arr);

	return bRet;
} // Stage5

DWORD Stage6(INT argc, PCHAR argv[])
{
	BOOL bRet = EXIT_FAILURE;
	CHAR input[INPUTLEN] = { 0 };
	DWORD d;
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

	ReadConsoleA(hStdin, input, INPUTLEN, &d, NULL);
	d -= 2;

	if (0 == d && 0 == strcmp(argv[1], EXPECTED_ARG2) && 0 == strcmp(argv[2], EXPECTED_ARG1) && argc >= EXPECTED_ARGC)
	{
		bRet = EXIT_SUCCESS;
	}

	return bRet;
} // Stage6

DWORD Stage7(VOID)
{
	BOOL bRet = EXIT_FAILURE;
	WIN32_FIND_DATAA FindFileData;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	DWORD dwRet = 0;
	CHAR input[INPUTLEN] = { 0 };

	hFind = FindFirstFileA(".\\..\\..\\.\\..\\*", &FindFileData);
	if (INVALID_HANDLE_VALUE == hFind)
	{
		return EXIT_FAILURE;
	}

	do
	{
		++dwRet;
	} while (FindNextFileA(hFind, &FindFileData) != 0);
	FindClose(hFind);

	scanf_s(WORDY, input, INPUTLEN);

	if (dwRet == atoi(input))
	{
		bRet = EXIT_SUCCESS;
	}
	return bRet;
} // Stage7

DWORD bonusStage(PCHAR arg1, INT * val2)
{
	if (!arg1) return EXIT_FAILURE;
	BOOL res = atoi(arg1) == *val2;
	return !res;
} // bonusStage

/* end of file */