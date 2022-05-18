#include "laps.h"

void race_state(int *id, size_t size)
{
    static race_list *head;
    race_list current = *head;

    if (size == 0)
        free_race(head);
    else
    {
        /*check id and create or increment cars*/
        while (current.next != NULL)
        {
            if (current.next == id)
                current.lap_num = current.lap_num + 1;
            else
                add_car(*head, id);
        }
        /*need to write print function*/
        print_race(head);
    }
}

race_list add_car(race_list head, const int id)
{
    race_list current;
    race_list new;
    unsigned int i = 0;

    if (!head || (head == NULL))
        return (NULL);
    new = malloc(sizeof(race_list));
    if (new == NULL)
        return (NULL);
    if (*head == NULL)
    {
        new.car_num = id;
        new.lap_num = 0;
        new.next = current.next;
        return (new);
    }
    else
    {
        current = *head;
        while (current != NULL)
        if (current.car_num < id)
            current = current.next;
        else
        {
            current.car_num = new;
            new.car_num = id;
            new.lap_num = 0;
            new.next = current.next;
        }
    }
    return (new);
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
        next = current.next;
        free(current);
        current = next;
    }
    free (next);
}

void print_race(race_list *head)
{
    race_list current;

    current = *head;
    while (current->next != NULL)
    printf("Car %d [%d laps]", current->car_num, current->lap_num);
}
