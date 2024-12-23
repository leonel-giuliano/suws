#ifndef __SUWS_FILE_H__
#define __SUWS_FILE_H__


#include <stdio.h>


#define APPLIST_PATH "suws.list"


// Imitates 'getline'.
// Allocates the buffer if it wasn't allocated and scans until a
// new line is encountered.
// If the size is smaller than the line size, it gets reallocated.
// On success, returns 0.
// If the end of the file was encountered, returns EOF.
// On failure, returns 1 if there was a problem allocating, with the
// parameters or reading the file
int fscanline(char **_BufferPtr, size_t *_SizePtr, FILE *_Fp);

// Returns a pointer to the applist path
char *getapp_path(char *_Buffer, size_t _Size);


#endif
