#include <stdlib.h>
#include <sys/types.h>

#include "wseek.h"


static struct wseek *head = NULL;
static struct wseek *tail = NULL;


ssize_t wk_getseek(int n, ssize_t *psk) {
    struct wseek *node;

    for(node = head; node != NULL && node->n != n; node = node->next);
    if(psk != NULL)
        *psk = (node != NULL && node->next != NULL) ? node->next->sk : -1;

    return (node == NULL) ? -1 : node->sk;
}


struct wseek *wk_mod(int n, size_t sk, struct wseek *seek) {
    struct wseek *node;

    // The node is the element next to the current one
    node = (seek == NULL) ? head : seek->next;
    if(node == NULL && (node = wk_add(n, sk)) == NULL) return NULL;

    node->n     = n;
    node->sk    = sk;

    // Instead of freeing the data that is not used, it
    // puts a '-1' to check in case it doesn't use the other elements
    if(node->next != NULL) node->next->n = -1;

    return node;
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


void wk_freelist(void) {
    struct wseek *node;

    while((node = head) != NULL) {
        head = head->next;
        free(node);
    }

    tail = NULL;
}
