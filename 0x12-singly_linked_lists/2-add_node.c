#include "lists.h"
#include <string.h>
#include <stdlib.h>

/**
 * add_node - adds a new node at the beginning of a linked list
 * @head:double pointer to the list_t list
 * @str: string to be duplicated
 * Pointer to the new node
 *
 * Return:the address of the new element, or NULL if it fails
 */

list_t *add_node(list_t **head, const char *str);

	list_t *new_node;
	char *dup_str;
	int len = 0;

	new_node = malloc(sizeof(list_t));

	if (new_node == NULL)
		return (NULL);

	dup_str = strdup(str);

	if (dup_str == NULL)
	{
		free(new_node);
		return (NULL);
	}
	while (str[len])
		len++;

	new_node->str = dup_str;
	new_node->len = len;
	new_node->next = *head;

	*head = new_node;
	return (new_node);
}
