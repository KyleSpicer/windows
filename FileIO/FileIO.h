#ifndef FILEIO_H
#define FILEIO_H

#include <Windows.h>

/**
* This function will open a file for reading and return a file HANDLE on success.
* 
* @param fileName: string for file to open for reading
* @return Success: valid file HANDLE
* @return Failure: Null
*/
HANDLE OpenFileToRead(TCHAR* fileName);


#endif /* FILEIO_H */

/* end of file */