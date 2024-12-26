#ifndef __SUWS_STR_H__
#define __SUWS_STR_H__


#include "file.h"


// Scans an entire line of the string, up to a new line or '\0'.
// If the buffer is NULL or the size is smaller than the line,
// it gets reallocated.
// On success, returns a pointer to the seek (the next character after
// the new line) or (char *)-1 if it reached the end.
// On failure, returns NULL if there was a problem allocating or
// if the string was set to NULL
char *sscanline(char **_PtrBuffer, size_t *_PtrSize, const char *_String);

// Saves inside the buffer the config variables either
// from the file content or the pred values.
// If the file content is NULL, the vars are the pred ones
void getcfvars(struct cfvars *_ConfigBuffer, const char *_FileContent);


#endif
