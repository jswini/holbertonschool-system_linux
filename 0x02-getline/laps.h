#ifndef LAPS_H
#define LAPS_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
/**
 *
 */
typedef struct list_s
{
    /* data */
    int car_num;
    int lap_num;
    struct list_s *next;
} race_list;

void race_state(int *id, size_t size);
race_list *add_car(const int car_id);
void free_race(race_list *head);
void print_race(race_list *head);
void check_car_id(race_list *head, int, id);
#endif /*LAPS_H*/
