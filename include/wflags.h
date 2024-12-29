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


// Converts from workspace num to the container flags index
#define WF_NTOCI(_WorkspaceNum) (1 << ((_WorkspaceNum) % sizeof(wflags_t) + 1))


// Checks the flag value inside the container flag.
// On success, returns either 0 or 1 depending on
// the flag value.
// On failure, returns -1 if the workspace num was negative
int wf_checkflag(int _WorkspaceNum);

// Sets the corresponding flag inside the container flag.
// On success, returns 0.
// On failure, returns -1 if the workspace num was negative
// or if there was a problem allocating
int wf_setflag(int _WorkspaceNum);

// Adds a new element to the list.
// On success, returns the pointer.
// On failure, returns NULL if there was a problem allocating
struct wflags *wf_add(int _ContainerIx);

// Frees all the elements in the list
void wf_freelist(void);


#endif
