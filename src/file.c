#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>


char *fgetcont(int fd, char **pbuf, size_t *pn) {
    size_t n;

    if((n = lseek(fd, 0, SEEK_END)) == 0) return (char *)-1;
    if(*pbuf == NULL || *pn <= n) {
        if((*pbuf = (char *)realloc(*pbuf, (n + 1) * sizeof(char))) == NULL) return NULL;
        *pn = n + 1;
    }

    if(read(fd, *pbuf, n) != n) return NULL;
    (*pbuf)[n] = '\0';

    return *pbuf;
}
