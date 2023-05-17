#include "laps.h"

/**
 * race_state - This is the function that updates each car's state in the race
 * @id: car identifier array
 * @size: size of the array
 *
 * Return: void
 */

void race_state(int *id, size_t size)
{
	/* list_t *race_status; */
	static list_t *head;
	int i;

	for (i = 0; id[i] != '\n'; i++)
	{
		if ((&head == NULL) || (id[i] != head->car_id))
			create_node(&head, id[i]);
		else
			update_node(head, id[i]);
	}
	print_list(head);
	if (size == 0)
		free_list(head);
}

list_t *create_node(list_t **head, const int car_num)
{
	list_t *new_node;
	list_t *current;
	int i;
	int last_car;

	if (!head || *head == NULL)
		return (NULL);
	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);
	if (head == NULL)
	{
		new_node->car_id = car_num;
		new_node->lap_num = 0;
		new_node->next = *head;
		*head = new_node;
		printf("Car %d joined the race\n", car_num);
	}
	else
	{
		current = *head;
		for (i = 1; current && i < last_car; i++)
			current = current->next;

		if (i != last_car)
		{
			free(new_node);
			return (NULL);
		}
		else
		{
			new_node->car_id = car_num;
			new_node->lap_num = 0;
			new_node->next = current->next;
			current->next = new_node;
		}
	}
	return (new_node);
}

list_t *update_node(list_t *head, const int car_num)
{
	list_t *current;

	current = head;
	while (current != NULL)
	{
		if (current->car_id == car_num)
		{
			current->lap_num = current->lap_num += 1;
			return (current);
		}
		else
			current = current->next;
	}
	return (current);
}

void print_list(const list_t *h)
{
	int count;

	printf("Race State:\n");
	for (count = 0; h != NULL; count++)
	{
		printf("Car %d [%d laps]\n", h->car_id, h->lap_num);
		h = h->next;
	}
}

/**
 * free_list - frees a linked list of ints
 * @head: start of the list
 *
 * Return: void
 */
void free_list(list_t *head)
{
	list_t *current;
	list_t *next;

	if (head == NULL)
		return;
	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(next);
}
