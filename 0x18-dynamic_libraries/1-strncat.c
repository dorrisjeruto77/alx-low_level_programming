#include "main.h"

/**
 * _strncat - function that concatenates two strings.
 * it will use at most n bytes from src
 * @dest: string
 * @src: string
 * @n: bytes
 * Return: dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
	{
		continue;
	}
	for (j = 0; src[j] != '\0' && j < n; j++)
	{
		dest[i + j] = src[j];
	}
	dest[i + j] = '\0';
	return (dest);
}
