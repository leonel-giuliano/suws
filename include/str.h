#ifndef __SUWS_STR_H__
#define __SUWS_STR_H__


#include "file.h"


// Saves inside the buffer the config variables either
// from the file content or the pred values.
// If the file content is NULL, the vars are the pred ones
void getcfvars(struct cfvars *_ConfigBuffer, const char *_FileContent);


#endif
