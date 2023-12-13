#include "main.h"

/**
 * _strstr - a function that locates a substring.
 * @haystack: String to be checked
 * @needle: String to be matched
 * Return: a pointer to the current position of haystack
 */
char *_strstr(char *haystack, char *needle)
{
	for (; *haystack != '\0'; haystack)
	{
		char *a = haystack;
		char *b = needle;

		while (*a == *b && *b != '\0')
		{
			a++;
			b++;
		}
		if (*b == '\0')
			return (haystack);
	}
	return (0);
}
