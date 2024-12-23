#include <stdio.h>
#include <stdlib.h>
#include <linux/limits.h>
#include <string.h>

#include "ws.h"
#include "file.h"
#include "catch.h"


int execapps(int wsnum) {
    int     e = 0, err;
    char    path[PATH_MAX], *line = NULL;
    size_t  lsiz;
    FILE    *fp;

    if((fp = fopen(getapp_path(path, sizeof(path)), "r")) == NULL)
        return -1;

    // Search the workspace num
    lsiz = COMSIZ;
    while((err = fscanline(&line, &lsiz, fp)) != 0) {
        int ntemp;

        // Check if it couldn't be scanned because of an error
        // or because it's not the workspace comment
        if(sscanf(line, WSNUM_SCAN, &ntemp) == EOF) {
            if(ferror(fp)) EH_EXECAPPS_FREE_LINE();
            continue;
        }

        if(wsnum == ntemp) break;
    }

    // In case there was an error or the end of the file was
    // found, meaning that the workspace num wasn't set
    if(err == 1)      EH_EXECAPPS_FREE_LINE();
    if(err == EOF)    goto free_line;

    free_line:  free(line);
    close_fp:   if(fclose(fp)) e = -1;
    return e;
}
