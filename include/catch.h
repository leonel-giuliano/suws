#ifndef __SUWS_CATCH_H__
#define __SUWS_CATCH_H__


/* ERROR HANDLERS */
// suws.c
#define EH_EXECAPPS_FREE_LINE() do {    \
    e = -1;                             \
    goto free_line;                     \
} while(0);

// ws.c

#define EH_GETWSNUM_CLOSE_PFP() do {    \
    n = -1;                             \
    goto close_pfp;                     \
} while(0);


#endif
