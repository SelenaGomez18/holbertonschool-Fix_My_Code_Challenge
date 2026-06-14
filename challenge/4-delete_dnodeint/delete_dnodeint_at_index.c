#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index
 * @head: pointer to the first element of the list
 * @index: index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp;
	dlistint_t *prev;
	dlistint_t *next;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	tmp = *head;

	while (tmp && i < index)
	{
		tmp = tmp->next;
		i++;
	}

	if (tmp == NULL)
		return (-1);

	prev = tmp->prev;
	next = tmp->next;

	if (prev != NULL)
		prev->next = next;
	else
		*head = next;

	if (next != NULL)
		next->prev = prev;

	free(tmp);

	return (1);
}
