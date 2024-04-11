#ifndef CONTROL_HANDLERS_H
#define CONTROL_HANDLERS_H

#include <Windows.h>

/**
 * @brief Sets up a control handler to handle console events.
 *
 * This function sets up a control handler to handle console events, such as
 * CTRL+C, in order to gracefully terminate the program.
 *
 * @return TRUE if the control handler was successfully set up, FALSE otherwise.
 */
BOOL WINAPI SetControlHandler(VOID);

/**
 * @brief Checks if the program is currently running.
 *
 * This function checks whether the program is currently running by
 * inspecting the value of a global variable.
 *
 * @return TRUE if the program is running, FALSE otherwise.
 */
BOOL WINAPI IsRunning(VOID);

#endif /* CONTROL_HANDLERS_H */

/* end of file */