#ifndef __SUWS_H__
#define __SUWS_H__


// Executes the commands in the file in respect
// to the workspace num.
// On success, returns 0.
// On failure, returns -1 if there was a problem allocating or
// opening or reading the file
int execapps(int _WorkspaceNum);


#endif
