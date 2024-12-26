#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"


char *sscanline(char **pbuf, size_t *pn, const char *cont) {
    char    *end, *ptemp;
    size_t  i = 0;
    size_t  len;

    if(cont == NULL) return NULL;
    len = ((end = strchr((cont), '\n')) == NULL) ? end - cont : strlen(cont);

    // Makes it so that the end of the string is scanned at last
    // without any more character
    if(end == NULL && len) end = (char *)&cont[len];
    if(len && (*pbuf == NULL || *pn < (len + 1) * sizeof(char))) {
        if((ptemp = (char *)realloc(*pbuf, (len + 1) * sizeof(char))) == NULL) return NULL;
        *pn = (len + 1) * sizeof(char);
        *pbuf = ptemp;
    }

    while(i < len) {
        (*pbuf)[i] = cont[i];
        i++;
    }

    (*pbuf)[i] = '\0';
    return (end != NULL) ? end + 1 : (char *)-1;
}


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
