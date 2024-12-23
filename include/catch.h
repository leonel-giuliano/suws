#ifndef __SUWS_CATCH_H__
#define __SUWS_CATCH_H__


/* ERROR HANDLERS */
// ws.c

#define EH_GETWSNUM_CLOSE_PFP() do {    \
    n = -1;                             \
    goto close_pfp;                     \
} while(0);


#endif
