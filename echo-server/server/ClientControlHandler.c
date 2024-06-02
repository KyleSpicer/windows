#include "ClientControlHandler.h"

#include <signal.h>
#include <wchar.h>

volatile sig_atomic_t gbServerRunning = TRUE;

static BOOL WINAPI CtrlHandler(DWORD fdwCtrlType)
{
	switch (fdwCtrlType)
	{
		case CTRL_C_EVENT:				// ctrl+c
		case CTRL_BREAK_EVENT:			// ctrl + break
		case CTRL_CLOSE_EVENT:			// when user closes window
		case CTRL_LOGOFF_EVENT:			// when user logs off
		case CTRL_SHUTDOWN_EVENT:		// when system is shutting down
			gbServerRunning = FALSE;
			return TRUE;

		default:
			return FALSE;
	}
}

BOOL WINAPI SetControlHandler(VOID)
{
	BOOL returnValue = FALSE;
	if (FALSE == SetConsoleCtrlHandler(CtrlHandler, TRUE))
	{
		goto EXIT_SET_CTRL_HANDLER;
	}
	wprintf(L"Control Handler Set...\n");
	returnValue = TRUE;

EXIT_SET_CTRL_HANDLER:
	return returnValue;
}

BOOL WINAPI ServerActive(VOID)
{
	return gbServerRunning;
}
