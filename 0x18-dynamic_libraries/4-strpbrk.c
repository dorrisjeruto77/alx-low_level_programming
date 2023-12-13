#include "main.h"

/**
 * _strpbrk - a function that locates a substring.
 * @s: string
 * @accept: string
 * Return: a pointer to the byte in s
 */

char *_strpbrk(char *s, char *accept)
{
	int b;

	while (*s)
	{
		for (b = 0; accept[b]; b++)
		{
			if (*s == accept[b])
			return (s);
		}
		s++;
	}
	return ('\0');
}
