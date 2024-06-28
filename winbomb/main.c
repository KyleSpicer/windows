#include <Windows.h>
#include <stdio.h>
#include "stages.h"

INT main(INT argc, PCHAR argv[])
{
	UNREFERENCED_PARAMETER(argc);
	UNREFERENCED_PARAMETER(argv);

	DWORD dwTotalStages = 5;
	DWORD dwRet = 0;
	SIZE_T data_len = 0;
	CHAR data[INPUTLEN] = { 0 };

	printf("Stage %d: ", ++dwRet);
	if (EXIT_FAILURE == Stage1())
	{
		goto EXIT_WINBOMB;
	}

	printf("Stage %d: ", ++dwRet);
	if (EXIT_FAILURE == Stage2(data))
	{
		goto EXIT_WINBOMB;
	}

	data_len = strlen(data);
	printf("Stage %d: ", ++dwRet);
	if (EXIT_FAILURE == Stage3(data_len))
	{
		goto EXIT_WINBOMB;
	}

	printf("Stage %d: ", ++dwRet);
	if (EXIT_FAILURE == Stage4(data))
	{
		goto EXIT_WINBOMB;
	}

	printf("Stage %d: ", ++dwRet);
	if (EXIT_FAILURE == Stage5(data_len))
	{
		goto EXIT_WINBOMB;
	}

	// Complete Last Stage
	++dwRet;

EXIT_WINBOMB:
	if (dwTotalStages < dwRet)
	{
		printf("Congratulations! You completed %d of %d stages.\n", --dwRet, dwTotalStages);
	}
	else
	{
		printf("Boom!!! You blew up on stage %d.\n", dwRet);
	}

	return dwRet;
}
