#include <stdio.h>
#include <tchar.h>

#include "DisplayErrors.h"

void DisplayErrorMessage(DWORD dwErrorCode) {
    LPTSTR lpMessageBuffer = NULL;

    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER |            // allocate memory for message buffer
        FORMAT_MESSAGE_FROM_SYSTEM |                // user system error message table
        FORMAT_MESSAGE_IGNORE_INSERTS,              // ignore any insert sequence in message
        NULL,                                       // message source, null for system messages
        dwErrorCode,                                // error code provided
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),  // language identifies, neutral language
        (LPTSTR)&lpMessageBuffer,                   // pointer to receive buffer pointer
        0,                                          // minimum number of characters to allocate for buffer
        NULL                                        // arguments for inserts in message
    );

    // Display the error message
    if (lpMessageBuffer != NULL) {
        _tprintf(_T("Error %lu: %s\n"), dwErrorCode, lpMessageBuffer);
        //  The caller should use the LocalFree function to free the buffer when it is no longer needed.
        LocalFree(lpMessageBuffer);
    }
    else {
        _tprintf(_T("Error %lu: Unable to retrieve error message.\n"), dwErrorCode);
    }
}

/* end of file */