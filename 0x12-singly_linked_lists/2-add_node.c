#include "lists.h"

/**
 *_strlen - get the lenght of a string
 * @s: string
 * Return: Always 0
 */
int - strlen(const char *s)
{
	int lenght = 0;

	while (*(s + length))
		length++;
	return (lenghth);
}

/**
 * add_node - adds a new node at the beginning of a linked list
 * @head:double pointer to the list_t list
 * @st: pointer to string
 *
 * Return:the address of the new element, or NULL if it fails
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->len = _strlen(str);
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}
