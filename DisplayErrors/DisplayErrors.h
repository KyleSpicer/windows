/**
 * @brief Displays the error message corresponding to the given error code.
 *
 * This function retrieves the error message associated with the provided error code
 * using the Windows API function FormatMessage. It then prints the error message
 * along with the error code to the standard output.
 *
 * @param dwErrorCode The error code for which to retrieve and display the error message.
 * @return void
 *
 * @remarks If the error message cannot be retrieved, the function prints an error message
 * indicating the failure to retrieve the error message along with the provided error code.
 * The caller is responsible for providing a valid error code.
 *
 * @see FormatMessage, GetLastError
 */

#include "Windows.h"

#ifndef DISPLAY_ERRORS_H
#define DISPLAY_ERRORS_H

void DisplayErrorMessage(DWORD dwErrorCode);

#endif /* DISPLAY_ERRORS_H */

/* end of file */