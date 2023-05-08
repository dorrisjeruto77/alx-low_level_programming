#include "main.h"

/**
 * _memcpy - a function that copies memory area.
 * @dest: memory area.
 * @src: memory area.
 * @n: bytes.
 * Return: a pointer to dest.
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;
	char *last = dest;
	char *from = src;

	for (i = 0; i < n; i++)
		last[i] = from[i];

	return (dest);
}
