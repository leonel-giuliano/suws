#include <stddef.h>
#include <stdlib.h>

#include "wslist.h"


static struct wslist *head = NULL;
static struct wslist *tail = NULL;


int wl_setflag(int b) {
    int             n = b / sizeof(wsflags_t);
    struct wslist   *node;

    if(head != NULL) {
        for(node = head; node != NULL; node = node->next) {
            if(node->ix != n) continue;

            node->flags |= CONV_BTCB(b);
            return 0;
        }
    }

    if((node = wl_newflags(n)) == NULL) return -1;
    node->flags |= CONV_BTCB(b);

    return 0;
}


void wl_freelist(void) {
    struct wslist *node;

    while((node = head) != NULL) {
        head = head->next;
        free(node);
    }

    tail = NULL;
}


struct wslist *wl_newflags(int n) {
    struct wslist *new;

    if((new = (struct wslist *)calloc(1, sizeof(struct wslist))) == NULL)
        return NULL;

    if(head == NULL)    head = new;
    else                tail->next = new;

    new->ix = n;
    tail    = new;

    return new;
}
