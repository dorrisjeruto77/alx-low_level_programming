#include "main.h"

/**
 * _memset - a function that fills memory with a constant byte.
 * @n: the number of bytes to be filled.
 * @s: the pointer to the memory.
 * @b: the value that the memory will be filled with.
 * Return: 0.
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;

	return (s);
}
