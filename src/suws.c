#include <stdio.h>
#include <linux/limits.h>

#include "ws.h"
#include "file.h"


int execapps(int wsnum) {
    int     e = 0, n;
    char    path[PATH_MAX], *line;
    size_t  lsiz;
    FILE    *fp;

    if((fp = fopen(getapp_path(path, sizeof(path)), "r")) == NULL)
        return -1;

    lsiz = COMSIZ;
    while((n = ))

    close_fp: if(fclose(fp)) e = -1;
    return e;
}
