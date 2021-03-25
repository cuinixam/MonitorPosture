#ifndef _types_h_
#define _types_h_

#ifndef NULL
#ifndef __cplusplus
#define NULL (void*)0
#else
#define NULL 0
#endif
#endif


typedef struct {
    unsigned char counter;
    int distance;
} radar_package_t;

#endif
