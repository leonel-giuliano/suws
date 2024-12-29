#include <stddef.h>
#include <stdlib.h>

#include "wflags.h"


static struct wflags *head = NULL;
static struct wflags *tail = NULL;


int wf_setflag(int n) {
    int             i;
    struct wflags   *node;

    if((i = n / sizeof(wflags_t)) < 0) return -1;
    for(node = head; node != NULL && node->i != i; node = node->next);

    // In case it wasn't allocated
    if(node == NULL && (node = wf_add(i)) == NULL) return -1;
    node->flags |= WF_NTOCI(n);

    return 0;
}


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
