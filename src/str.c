#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"


char *sscanline(char **pbuf, size_t *pn, const char *cont) {
    char    *end, *ptemp;
    size_t  len, siz;

    if(cont == NULL) return NULL;
    len = ((end = strchr((cont), '\n')) != NULL) ? end - cont : strlen(cont);
    siz = (len + 1) * sizeof(char);

    if(len && (*pbuf == NULL || *pn < siz)) {
        if((ptemp = (char *)realloc(*pbuf, siz)) == NULL) return NULL;
        *pn     = siz;
        *pbuf   = ptemp;
    }

    memset(*pbuf, 0, *pn);
    strncpy(*pbuf, cont, len);
    return (end == NULL && !len) ? (char *)-1 : end + 1;
}


void getcfvars(struct cfvars *cbuf, const char *cont) {
    char    *seek, *pathtemp;
    char    *path   = APPLIST_PATH;
    size_t  usleep  = PRED_USLEEP;
    size_t  pathlen = sizeof(APPLIST_PATH) - 1;

    if(cont != NULL) {
        if((seek = strstr(cont, PATH_VAR)) != NULL) {
            pathtemp = seek + sizeof(PATH_VAR) - 1;

            if(pathtemp[0] != '\n' && pathtemp[0] != '\0') {
                path    = pathtemp;
                pathlen = 0;
                while(path[pathlen] != '\n' && path[pathlen] != '\0')
                    if(++pathlen == sizeof(APPLIST_PATH) - 1) break;
            }
        }

        if((seek = strstr(cont, USLEEP_VAR)) != NULL)
            sscanf(seek + sizeof(USLEEP_VAR) - 1, "%lu", &usleep);
    }

    memset(cbuf, 0, sizeof(struct cfvars));
    strncpy(cbuf->path, path, pathlen);
    cbuf->usleep        = usleep;
    cbuf->path[pathlen] = '\0';
}
