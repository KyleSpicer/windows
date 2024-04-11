#include "ControlHandlers.h"
#include <signal.h>
#include <tchar.h>

volatile sig_atomic_t gb_is_running = TRUE;

/**
 * @brief Handles control events, such as CTRL+C.
 *
 * This function is called when a control event, such as CTRL+C, occurs.
 * It updates a global variable to indicate that the program should terminate.
 *
 * @param fdwControlType The type of control event that occurred.
 *
 * @return TRUE if the control event was handled, FALSE otherwise.
 */
static BOOL WINAPI ControlHandler(DWORD fdwControlType);

BOOL WINAPI SetControlHandler(VOID)
{
	BOOL returnValue = FALSE;
	if (FALSE == SetConsoleCtrlHandler(ControlHandler, TRUE)) {
		goto EXIT_SET_CTRL_HANDLER;
	}
	_tprintf(_T("Console Handler has been set.\n"));
	returnValue = TRUE;

EXIT_SET_CTRL_HANDLER:
	return returnValue;
}

BOOL WINAPI IsRunning(VOID)
{
	BOOL result = FALSE;
	result = (FALSE != gb_is_running);
	return result;
}

static BOOL WINAPI ControlHandler(DWORD fdwControlType)
{
	switch (fdwControlType)
	{
		// handle (ctrl + c) signal
	case CTRL_C_EVENT:
		gb_is_running = 0;
		return TRUE;

	default:
		return FALSE;
	}
}

/* end of file */