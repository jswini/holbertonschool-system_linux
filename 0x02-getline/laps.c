#include "laps.h"

void race_state(int *id, size_t size)
{
	static race_list *head;
       	printf("0");
	current = malloc(sizeof(race_list));
	current = head;
	unsigned int i;
    if (size == 0)
        free_race(head);
    else
    {
        /*check id and create or increment cars*/
	    for (i = 0; i < size; i++)
	    {
		    check_car_id(&head, id[i]);
	    }
	    print_race(head);
    }
}

void check_car_id(race_list **head, id)
{
	/*do the thing*/
	race_list *current;

	if (head == NULL)
	{
		head = add_car(car_id);
	}
	current = head;
	while (current != NULL)
	{
		if (current->car_num == id)
		{
			current->lap_num++;
		}
		else
		{
/*
1) create new car as temp
2) swap cars to correct position
      a) figure where the car belongs
      b) change pointer of temp and previous so it is in the correct order
*/
			add_car(id);
		}
	}
}

race_list *add_car(const int car_id)
{
    race_list *new;

    new = malloc(sizeof(race_list));
    if (new == NULL)
        return (NULL);
    new->car_num = id;
    new->lap_num = 0;
    new->next = NULL;

    return (new);
}

void free_race(race_list *head)
{
    race_list *current;

    if (head == NULL)
        return;
    while (head != NULL)
    {
        current = head;
        head = head->next;
        free(current);
     }
    free(head);
}

void print_race(race_list *head)
{
    race_list current;

    current = *head;
    while (current.next != NULL)
	    printf("Car %d [%d laps]", current.car_num, current.lap_num);
}
