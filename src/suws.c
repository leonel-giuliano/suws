#include <stdio.h>
#include <linux/limits.h>

#include "file.h"


int execapps(int wsnum) {
    int     e = 0;
    char    path[PATH_MAX];
    FILE    *fp;

    if((fp = fopen(getapp_path(path, sizeof(path)), "r")) == NULL)
        return -1;

    close_fp: if(fclose(fp)) e = -1;
    return e;
}
