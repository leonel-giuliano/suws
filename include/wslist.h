#ifndef __SUWS_WSLIST_H__
#define __SUWS_WSLIST_H__


#include <stdint.h>


typedef uint_fast8_t wsflags_t;

struct wslist {
    int             ix;     /* Container index */
    wsflags_t       flags;
    struct wslist   *next;
};


// Converts the bit flag to the container bit position
#define CONV_BTCB(_Bit) (1 << ((_Bit) % sizeof(wsflags_t) + 1))


// Returns the state of the flag
int wl_checkflag(int _Bit);

// Sets the flag to the corresponding container flag.
// On success, returns 0.
// On failure, returns -1 if there was a problem allocating
int wl_setflag(int _Bit);

// Frees all the elements from the list
void wl_freelist(void);

// Adds a new element to the workspace list of flags.
// On success, returns a pointer to it.
// On failure, returns -1 if there was a problem allocating
struct wslist *wl_newflags(int _ContainerIx);


#endif
