#include <stdio.h>
#include <string.h>

#include "ws.h"


static struct wsnum ws;


int getwsnum(void) {
    int     n;
    FILE    *pfp;

    return n;
}


void modwscomm(void) {
    memset(&ws, 0, sizeof(ws));

    strncpy(ws.comm,        X11_COMM,           sizeof(ws.comm) - 1);
    strncpy(ws.scan_output, X11_SCAN_OUTPUT,    sizeof(ws.scan_output) - 1);
}
