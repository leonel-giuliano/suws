#ifndef __SUWS_CATCH_H__
#define __SUWS_CATCH_H__


#include <stdio.h>
#include <errno.h>
#include <string.h>


#define EMSGSIZ 128


#define EMSG(_ErrnoVal, _Msg) do {                              \
    fprintf(stderr, "(%s:%d) %s", __FILE__, __LINE__, _Msg);    \
    if((_ErrnoVal) > 0) fprintf(stderr,": %s (ERRNO::%d)",      \
    strerror(_ErrnoVal), _ErrnoVal);                            \
    putc('\n', stderr);                                         \
} while(0);

#define EHANDLER(_Msg, _ExitVal, _ErrorHandler) do {    \
    int __errno_val = errno;                            \
    EMSG(__errno_val, _Msg);                            \
    e = (_ExitVal);                                     \
    _ErrorHandler;                                      \
} while(0);


/* ERROR HANDLERS */
// suws.c

#define EH_EXECAPPS(_ErrorHandler)                      \
EHANDLER("There was a problem executing the commands",  \
EXIT_EXECAPPS, _ErrorHandler);

#define EH_EXECAPPS_FREE_LINE() do {    \
    e = -1;                             \
    goto free_line;                     \
} while(0);

// ws.c

#define EH_GETWSNUM_CLOSE_PFP() do {    \
    n = -1;                             \
    goto close_pfp;                     \
} while(0);


#endif
