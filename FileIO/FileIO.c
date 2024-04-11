/** FileIO is used to implement various file input & output operations using the Windows API
*
* @author Kyle Spicer
* @cite https://learn.microsoft.com/en-us/windows/win32/fileio/opening-a-file-for-reading-or-writing
*/

#include "FileIO.h"
#include <tchar.h>

HANDLE OpenFileToRead(TCHAR* fileName) {
	HANDLE hFile = NULL;

	if (NULL == fileName) {
		goto EXIT_OPEN_FILE;
	}

	hFile = CreateFile(fileName,               // file to open
		GENERIC_READ,          // open for reading
		FILE_SHARE_READ,       // share for reading
		NULL,                  // default security
		OPEN_EXISTING,         // existing file only
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, // normal file
		NULL);                 // no attr. template

	if (INVALID_HANDLE_VALUE == hFile)
	{
		_tprintf(TEXT("CreateFG: unable to open file \"%s\" for read.\n"), fileName);
		goto EXIT_OPEN_FILE;
	}

EXIT_OPEN_FILE:
	return hFile;
}

/* end of file */