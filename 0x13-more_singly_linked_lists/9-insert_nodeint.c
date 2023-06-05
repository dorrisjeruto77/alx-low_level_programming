#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - inserts a new node in a linked list,
 * at a given position
 * @head: pointer to the first node in the list
 * @idx: index where the new node is added
 * @n: integer
 *
 * Return: pointer to the new node, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new;
	
	new = malloc(sizeof(listint_t));
	
	if (!new || !head)
		return (NULL);

	new->n = n;
	new->next = NULL;

	current = *head;
	prev = NULL;
	
	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	for (i = 0; i < idx; i++)
	{
		if (current == NULL || current->next == NULL)
			return (NULL);
	
		prev = current;
		current = current->next;	
	}
	new->next = current;
	prev->next = new;
	
	return (new);
}
	
