#include "laps.h"

void race_state(int *id, size_t size)
{
    if (size == 0)
        free_race(head);
    else
    {
        /*check id and create or increment cars*/
    }
}

race_list add_car(list_t *head, const int id)
{
    race_list current;
    race_list next;

    if (current->car_num > id)
        current = current->next;
    else
        {
            malloc(sizeof(race_list));
            current->car_num = id;
            current->lap_num - 0;
            current->next = next;
        }
}

void free_race(race_list *head)
{
    race_list current;
    race_list next;

    if (head == NULL)
        return;
    current = head;
    while (current != NULL)
    {
        next = current->next;
        free(current->car_id);
        free(current->lap_num);
        free(current);
        current = next;
    }
    free next;
}
