#include "lists.h"

/**
 * print_list - prints all the elements of a linked list
 * @h: pointer to the struct
 * elements of all a list_t list
 * Return: the number of nodes printed
 */

size_t print_list(const list_t *h)
{
	unsigned int i;

	i = 0;
	if (h == NULL)
		return (0);
	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
		h = h->next;
		i++;
	}
	return (i);
}
