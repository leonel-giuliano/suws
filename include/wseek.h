#ifndef __SUWS_WSEEK_H__
#define __SUWS_WSEEK_H__


#include <sys/types.h>


// Struct for the line position of the worskpace
// number line inside the file
struct wseek {
    int             n;
    size_t          sk;
    struct wseek    *next;
};


// Gets the position where the worskpace num is inside the file.
// Saves inside the next seek the following wokspace num position.
// If it's set to NULL, then it doesn't get saved.
// If there is no other workspace num, it gets set to '(size_t)-1'.
// Returns the position or '(size_t)-1' if it wasn't found on the list
size_t wk_getseek(int _WorkspaceNum, size_t *_PtrNextSeek);

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
