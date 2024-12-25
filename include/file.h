#ifndef __SUWS_FILE_H__
#define __SUWS_FILE_H__


#include <stddef.h>


// Gets all the content of the file inside the buffer.
// If the buffer is NULL or it's smaller than the file content,
// it reallocates it to fit.
// On success, returns a pointer to the buffer or (char *)-1
// if the file was empty
// On failure, returns NULL if there was a problem allocating
char *fgetcont(int _FileDescriptor, char **_PtrBuffer, size_t *_PtrSize);


#endif
