#include <stdio.h>
#include <stdlib.h>
#include <linux/limits.h>
#include <string.h>

#include "suws.h"
#include "ws.h"
#include "wslist.h"
#include "file.h"
#include "catch.h"


int main(void) {
    exit_t e = 0;

    if(execapps(1)) EH_EXECAPPS(goto free_wlist);
    if(execapps(1)) EH_EXECAPPS(goto free_wlist);

    free_wlist: wl_freelist();
    return e;
}


int execapps(int wsnum) {
    int     e = 0, err;
    char    path[PATH_MAX], *line = NULL;
    size_t  lsiz;
    FILE    *fp;

    if(wl_checkflag(wsnum)) return 0;

    if((fp = fopen(getapp_path(path, sizeof(path)), "r")) == NULL)
        return -1;

    // Search the workspace num
    lsiz = COMSIZ;
    while((err = fscanline(&line, &lsiz, fp)) == 0) {
        int ntemp;

        // Skip scanning for empty line
        if(line[0] == '\0') continue;

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

    while((err = fscanline(&line, &lsiz, fp)) == 0) {
        int ntemp;

        if(line[0] == '\0') continue;
        // Break when a new workspace comment was found
        if(sscanf(line, WSNUM_SCAN, &ntemp) == 1) break;
        if(ferror(fp)) EH_EXECAPPS_FREE_LINE();

        system(line);
    }

    if(err == 1)            EH_EXECAPPS_FREE_LINE();
    if(wl_setflag(wsnum))   EH_EXECAPPS_FREE_LINE();

    free_line:  free(line);
    close_fp:   if(fclose(fp)) e = -1;
    return e;
}
