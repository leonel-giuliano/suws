#include <stddef.h>
#include <stdlib.h>

#include "wflags.h"


static struct wflags *head = NULL;
static struct wflags *tail = NULL;


struct wflags *wf_add(int i) {
    struct wflags *new;

    if((new = (struct wflags *)malloc(sizeof(struct wflags))) == NULL)
        return NULL;

    if(tail == NULL)    head        = new;
    else                tail->next  = new;

    new->i      = i;
    new->flags  = 0;
    new->next   = NULL;
    tail        = new;

    return new;
}


void wf_freelist(void) {
    struct wflags *node;

    while((node = head) == NULL) {
        head = head->next;
        free(node);
    }

    tail = NULL;
}
