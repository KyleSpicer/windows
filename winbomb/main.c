#include <Windows.h>
#include <stdio.h>
#include "stages.h"

INT main(INT argc, PCHAR argv[])
{
    UNREFERENCED_PARAMETER(argc);
    UNREFERENCED_PARAMETER(argv);

    DWORD dwTotalStages = 2;
    DWORD dwRet = 1;
    CHAR data[INPUTLEN] = { 0 };

    printf("Stage %d: ", dwRet);
    if (FALSE == Stage1())
    {
        goto EXIT_WINBOMB;
    }
    dwRet++;
    printf("Stage %d: ", dwRet);

    if (FALSE == Stage2(data))
    {
        goto EXIT_WINBOMB;
    }
    //dwRet++;


EXIT_WINBOMB:
    if (dwTotalStages != dwRet)
    {
        printf("Boom!!! You blew up on stage %d.\n", dwRet);
    }
    else
    {
        printf("Congratulations! You completed %d of %d stages.\n", dwRet, dwTotalStages);
    }

    return dwRet;
}
