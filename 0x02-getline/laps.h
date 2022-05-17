#ifndef LAPS.H
#define LAPS.H
#include <stdio.h>
#include <stdlib.h>
/**
 *
 */
typedef struct list_s
{
    /* data */
    int car_num;
    int lap_num;
    struct list_s next;
} race_list;

void race_state(int *id, size_t size);

#endif /*LAPS_H*/
