#include <stdio.h>
#include <string.h>

#include "ws.h"
#include "catch.h"


static struct wsnum ws = { 0 };


int getwsnum(void) {
    int     n;
    FILE    *pfp;

    if((pfp = popen(ws.comm, "r")) == NULL)     return -1;
    if(fscanf(pfp, ws.scan_output, &n) != 1)    EH_GETWSNUM_CLOSE_PFP();

    close_pfp: if(pclose(pfp)) n = -1;
    return n;
}


void modwscomm(void) {
    strncpy(ws.comm,        X11_COMM,           sizeof(ws.comm) - 1);
    strncpy(ws.scan_output, X11_SCAN_OUTPUT,    sizeof(ws.scan_output) - 1);
}
