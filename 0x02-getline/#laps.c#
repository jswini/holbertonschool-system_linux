#include "laps.h"

void race_state(int *id, size_t size)
{
	static race_list *head;
	race_list *current;
	printf("0");
	current = malloc(sizeof(race_list));
	current = head;

    if (size == 0)
        free_race(head);
    else
    {
        /*check id and create or increment cars*/
        while (current->next != NULL)
        {
            if (current->car_num == *id)
            {
                current->lap_num = current->lap_num + 1;
                printf("1");
            }
             else
             {
                    add_car(head, *id);
                    printf("2");
             }
        }
        /*need to write print function*/
         print_race(head);
    }
}

race_list add_car(race_list *head, const int id)
{
    race_list *current;
    race_list *new;

    new = malloc(sizeof(race_list));
    if (new == NULL)
        return(*new);
    if (head == NULL)
    {
        new->car_num = id;
        new->lap_num = 0;
        new->next = NULL;
        return(*new);
    }
    else
    {
        current = head;
        while (current != NULL)
        if (current->car_num < id)
            current = current->next;
        else
        {
            current = new;
            new->car_num = id;
            new->lap_num = 0;
            new->next = current->next;
        }
    }
    return (*new);
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

