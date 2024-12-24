#ifndef __SUWS_WSLIST_H__
#define __SUWS_WSLIST_H__


#include <stdint.h>


typedef uint_fast8_t wsflags_t;

struct wslist {
    int             ix;     /* Container index */
    wsflags_t       flags;
    struct wslist   *next;
};


#endif
