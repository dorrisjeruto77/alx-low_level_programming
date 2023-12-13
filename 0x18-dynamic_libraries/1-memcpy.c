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
	int p = 0;
	int i = n;

	for (; p < i; p++)
	{
		dest[p] = src[p];
	}
	return (dest);
}
