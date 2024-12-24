#include <stddef.h>
#include <stdlib.h>

#include "wslist.h"


static struct wslist *head = NULL;
static struct wslist *tail = NULL;


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
