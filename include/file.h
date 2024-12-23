#ifndef __SUWS_FILE_H__
#define __SUWS_FILE_H__


#include <stddef.h>


#define APPLIST_PATH "suws.list"


// Returns a pointer to the applist path
char *getapp_path(char *_Buffer, size_t _Size);


#endif
