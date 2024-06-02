#include "SharedControlHandler.h"

#include <signal.h>

volatile sig_atomic_t gbServerActive = TRUE;

static BOOL WINAPI ControlHandler(DWORD fdwControlType);

BOOL WINAPI ServerActive(VOID)
{
	return (TRUE == gbServerActive);
}

BOOL WINAPI SetControlHandler(VOID)
{
	BOOL bReturnValue = FALSE;
	if (FALSE == SetConsoleCtrlHandler(ControlHandler, TRUE))
	{
		goto EXIT_SET_CTRL_HANDLER;
	}
	wprintf(L"Shared Control Handler set...\n");
	bReturnValue = TRUE;

EXIT_SET_CTRL_HANDLER:
	return bReturnValue;
}

static BOOL WINAPI ControlHandler(DWORD fdwControlType)
{
	switch (fdwControlType)
	{
	case CTRL_C_EVENT:
		gbServerActive = FALSE;
		return TRUE;

	default:
		return FALSE;
	}
}