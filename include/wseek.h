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


// Modifies the next element of the list.
// If the element is NULL, it starts with the head of the list.
// If there is no more elements in the list, it starts allocating space.
// Makes the next element of the returned pointer have a '-1' in the
// workspace number in order to check the end of the list.
// On success, returns a pointer to the next element.
// On failure, returns NULL if there was a problem allocating
struct wseek *wk_mod(int _WorkspaceNum, size_t _Seek, struct wseek *_PreviousElement);

// Adds a new element to the list.
// On success, returns a pointer to the element.
// On failure, returns NULL if there was a problem allocating
struct wseek *wk_add(int _WorkspaceNum, size_t _Seek);

// Frees the entire list
void wk_freelist(void);



#endif
