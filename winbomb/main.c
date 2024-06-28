#include <Windows.h>
#include <stdio.h>
#include "stages.h"

INT main(INT argc, PCHAR argv[])
{

	DWORD dwTotalStages = 6;
	DWORD dwRet = 0;
	SIZE_T data_len = 0;
	CHAR data[INPUTLEN] = { 0 };

	// Stage 1
	printf("Stage %d: ", ++dwRet);
	if (EXIT_FAILURE == Stage1())
	{
		goto EXIT_WINBOMB;
	}

	// Stage 2
	printf("Stage %d: ", ++dwRet);
	if (EXIT_FAILURE == Stage2(data))
	{
		goto EXIT_WINBOMB;
	}
	data_len = strlen(data);

	// Stage 3
	printf("Stage %d: ", ++dwRet);
	if (EXIT_FAILURE == Stage3(data_len))
	{
		goto EXIT_WINBOMB;
	}

	// Stage 4
	printf("Stage %d: ", ++dwRet);
	if (EXIT_FAILURE == Stage4(data))
	{
		goto EXIT_WINBOMB;
	}

	// Stage 5
	printf("Stage %d: ", ++dwRet);
	if (EXIT_FAILURE == Stage5(data_len))
	{
		goto EXIT_WINBOMB;
	}

	// Stage 6
	printf("Stage %d: ", ++dwRet);
	if (EXIT_FAILURE == Stage6(argc, argv))
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
