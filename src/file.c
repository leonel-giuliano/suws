#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>


char *fgetcont(int fd, char **pbuf, size_t *pn) {
    char            *ptemp;
    size_t          n;
    struct flock    lk;

    if((n = lseek(fd, 0, SEEK_END)) == 0) return (char *)-1;
    if(*pbuf == NULL || *pn <= n) {
        if((ptemp = (char *)realloc(*pbuf, (n + 1) * sizeof(char))) == NULL) return NULL;
        *pn     = (n + 1) * sizeof(char);
        *pbuf   = ptemp;
    }


    lk.l_type   = F_RDLCK;
    lk.l_whence = SEEK_SET;
    lk.l_start  = 0;
    lk.l_len    = 0;
    if(fcntl(fd, F_SETLK, &lk)) return NULL;

    lseek(fd, 0, SEEK_SET);
    if(read(fd, *pbuf, n) != n) return NULL;
    (*pbuf)[n] = '\0';

    lk.l_type = F_UNLCK;
    if(fcntl(fd, F_SETLK, &lk)) return NULL;

    return *pbuf;
}
