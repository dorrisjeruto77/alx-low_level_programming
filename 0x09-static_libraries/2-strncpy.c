#include "main.h"

/**
 * _strncpy - a function that copys the strings.
 * @dest: an input string
 * @src: an input string
 * @n: an input integer
 * Return: A pointer to the resulting string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int b = 0;

		while (b < n && src[b] != '\0')
		{
			dest[b] = src[b];
			b++;
		}
		while (b < n)
		{
			dest[b] = '\0';
			b++;
		}
		return (dest);
}
