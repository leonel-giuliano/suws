#ifndef __SUWS_WSEEK_H__
#define __SUWS_WSEEK_H__


#include <stddef.h>


// Struct for the line position of the worskpace
// number line inside the file
struct wseek {
    int             n;
    size_t          sk;
    struct wseek    *next;
};


// Frees the entire list
void wk_freelist(void);

// Adds a new element to the list.
// On success, returns a pointer to the element.
// On failure, returns NULL if there was a problem allocating
struct wseek *wk_add(int _WorkspaceNum, size_t _Seek);


#endif
