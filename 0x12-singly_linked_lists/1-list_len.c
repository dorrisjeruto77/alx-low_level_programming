#include <stdlib.h>
#include "lists.h"

/**
 * list_len - returns the number of elements in alinked list
 * @h: pointer to the list_t list
 *
 * Return: number of elements in h
 */

size_t list _len(const list_t *h)
{
	size_t n = 0;

	while (h)
	{
		n++;
		h = h->next;
	}
	return (n);
}
