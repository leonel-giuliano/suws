#include <stdio.h>
#include <string.h>

#include "file.h"


void getcfvars(struct cfvars *cbuf, const char *cont) {
    char    *seek;
    char    *path   = APPLIST_PATH;
    size_t  usleep  = PRED_USLEEP;
    size_t  pathlen = sizeof(APPLIST_PATH) - 1;

    if(cont != NULL) {
        if((seek = strstr(cont, PATH_VAR)) != NULL) {
            path = seek + sizeof(PATH_VAR) - 1;
            pathlen = 0;
            while(path[pathlen] != '\n' && path[pathlen] != '\0')
                if(++pathlen == sizeof(APPLIST_PATH) - 1) break;
        }

        if((seek = strstr(cont, USLEEP_VAR)) != NULL)
            sscanf(seek + sizeof(USLEEP_VAR) - 1, "%lu", &usleep);
    }

    memset(cbuf, 0, sizeof(struct cfvars));
    strncpy(cbuf->path, path, pathlen);
    cbuf->usleep        = usleep;
    cbuf->path[pathlen] = '\0';
}
