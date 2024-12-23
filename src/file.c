#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"


int fscanline(char **pbuf, size_t *pn, FILE *fp) {
    char    c;
    size_t  i = 0;

    // Allocates the buffer if it was passed without
    // being allocated before
    if(*pbuf == NULL) {
        if(!*pn) return 0;
        if((*pbuf = (char *)malloc(*pn * sizeof(char))) == NULL)
            return 1;
    } else if(!*pn) return 1;

    // The '-1' is because it needs space for the '\0'
    while(i < *pn - 1 && (c = getc(fp)) != '\n' && c != EOF)
        (*pbuf)[i++] = c;

    // If the line was greater than the buffer size
    if(c != '\n' && c != EOF) {
        // Count the amount of chars left
        size_t n = 0;
        while((c = getc(fp)) != '\n' && c != EOF) n++;

        (*pn) += n;
        if(n && (*pbuf = (char *)realloc(*pbuf, *pn * sizeof(char))) == NULL)
            return 1;

        // Go back and scan the data
        // The '-1' is beacuse the '\n' doesn't get saved
        fseek(fp, -1 * (n + 1), SEEK_CUR);
        if(fgets(*pbuf + i, n, fp) == NULL) return 1;
    }

    (*pbuf)[i] = '\0';

    // Makes the EOF get scanned in the next call
    if(c == EOF) ungetc(c, fp);
    return (!i && c == EOF) ? EOF : 0;
}


char *getapp_path(char *buf, size_t n) {
    strncpy(buf, APPLIST_PATH, n - 1);
    buf[n] = '\0';

    return buf;
}
