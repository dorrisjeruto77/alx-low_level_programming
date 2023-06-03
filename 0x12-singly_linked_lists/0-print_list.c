#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_list - prints all the elements of a linked list
 * @h: pointer to the struct
 * elements of all a list_t list
 * Return: the number of nodes printed
 */

size_t print_list(const list_t *h)
{
	size_t count = 0;

	const list_t* current = h;
	
	while (current != NULL)
	{
		if (current->str != NULL)
		{
			printf("[%lu] %s\n", current->len, current->str);
			count++;
		}
		current = current->next;
return count;
}

int main(void)
{
	list - t node1 = {"Hello", 5, NULL};
	list - t node2 = {"World", 5, NULL};
	node1.next = &node2;

	size - t count = print - list(&node1);
	printf("Count: %lu\n", count);

return 0;
}
