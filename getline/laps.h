#ifndef LAPS_H
#define LAPS_H

#include <stdio.h>
#include <stdlib.h>
/**
 * struct list_s - singly linked list
 * @car_id: unique id for each car in race
 * @lap_num: lap number of this car
 * @next: pointer to next node
 *
 * Description: linked list of cars in a race
 */
typedef struct list_s
{
	int car_id;
	int lap_num;
	struct list_s *next;
} list_t;

void race_state(int *id, size_t size);
list_t *create_node(list_t **head, const int car_num);
list_t *update_node(list_t *head, const int car_num);
void print_list (const list_t *h);
void free_list(list_t *head);

#endif /*LAPS.H*/
