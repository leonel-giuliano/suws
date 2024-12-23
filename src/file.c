#include <stddef.h>
#include <string.h>

#include "file.h"


char *getapp_path(char *buf, size_t n) {
    strncpy(buf, APPLIST_PATH, n - 1);
    buf[n] = '\0';

    return buf;
}
