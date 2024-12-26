#ifndef __SUWS_FILE_H__
#define __SUWS_FILE_H__


#include <stddef.h>
#include <linux/limits.h>
#include <sys/types.h>


/* CONFIG */

#define APPLIST_PATH    "suws.list"
#define PRED_USLEEP     1000

#define PATH_VAR    "path="
#define USLEEP_VAR  "time="

// All the configuration variables
struct cfvars {
    char    path[PATH_MAX];
    time_t  usleep;
};


// Gets all the content of the file inside the buffer.
// If the buffer is NULL or it's smaller than the file content,
// it reallocates it to fit.
// On success, returns a pointer to the buffer or (char *)-1
// if the file was empty
// On failure, returns NULL if there was a problem allocating
char *fgetcont(int _FileDescriptor, char **_PtrBuffer, size_t *_PtrSize);


#endif
