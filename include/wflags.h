#ifndef __SUWS_WFLAGS_H__
#define __SUWS_WFLAGS_H__


#include <stdint.h>


typedef uint_fast8_t wflags_t;

// Dynamic list for a set of the workspace flags
struct wflags {
    int             i;      /* Container ix */
    wflags_t        flags;
    struct wflags   *next;
};


#define WF_NTOCI(_WorkspaceNum) (1 << ((_WorkspaceNum) % sizeof(wflags_t) + 1))


// Sets the corresponding flag inside the container flag.
// On success, returns 0.
// on failure, returns -1 if there was a problem allocating
int wf_setflag(int _WorkspaceNum);

// Adds a new element to the list.
// On success, returns the pointer.
// On failure, returns NULL if there was a problem |
struct wflags *wf_add(int _ContainerIx);

// Frees all the elements in the list
void wf_freelist(void);


#endif
