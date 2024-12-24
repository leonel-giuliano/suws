#ifndef __SUWS_WSLIST_H__
#define __SUWS_WSLIST_H__


#include <stdint.h>


typedef uint_fast8_t wsflags_t;

struct wslist {
    int             ix;     /* Container index */
    wsflags_t       flags;
    struct wslist   *next;
};


// Adds a new element to the workspace list of flags.
// On success, returns a pointer to it.
// On failure, returns -1 if there was a problem allocating
struct wslist *wl_newflags(int _ContainerIx);


#endif
