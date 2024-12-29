#ifndef __SUWS_WFLAGS_H__
#define __SUWS_WFLAGS_H__


#include <stdint.h>


typedef uint_fast8_t wflag_t;

// Dynamic list for a set of the workspace flags
struct wflags {
    int             i;      /* Container ix */
    wflag_t         flags;
    struct wflags   *next;
};


// Adds a new element to the list.
// On success, returns the pointer.
// On failure, returns NULL if there was a problem allocating
struct wflags *wf_add(int _ContainerIx);

// Frees all the elements in the list
void wf_freelist(void);


#endif
