#ifndef __SUWS_WS_H__
#define __SUWS_WS_H__


#define COMSIZ 128

struct wsnum {
    char comm[COMSIZ];
    char scan_output[COMSIZ];
};


/* COMMANDS */

#define X11_COMM        "xprop -root -notype _NET_CURRENT_DESKTOP"
#define X11_SCAN_OUTPUT "_NET_CURRENT_DESKTOP=%d"

// Scans the current workspace num from the command set.
// On success, returns the workspace num
// Returns -1 if there was a problem opening a pipe to
// the command or reading the output
int getwsnum(void);

// Selects the command and scan format of the output
// to know the workspace num.
// MUST BE USED BEFORE 'getwsnum'
void modwscomm(void);


#endif
