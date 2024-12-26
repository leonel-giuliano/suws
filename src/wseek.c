#include <stddef.h>
#include <stdlib.h>

#include "wseek.h"


static struct wseek *head = NULL;
static struct wseek *tail = NULL;


void wk_freelist(void) {
    struct wseek *node;

    while((node = head) != NULL) {
        head = head->next;
        free(node);
    }

    tail = NULL;
}


struct wseek *wk_add(int n, size_t sk) {
    struct wseek *new;

    if((new = (struct wseek *)calloc(1, sizeof(struct wseek))) == NULL)
        return NULL;

    if(tail == NULL)    head        = new;
    else                tail->next  = new;

    new->n      = n;
    new->sk     = sk;
    new->next   = NULL;
    tail        = new;

    return new;
}
