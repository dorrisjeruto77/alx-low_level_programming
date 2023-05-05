#include "main.h"

/**
 * _strncpy - copies n elements of src to replace
 * dest elements
 * @src: elements to be copied
 * @dest: elements to be replaced
 * @n: maximum numbers to be copied
 * Return: pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
int i;
for (i = 0; i < n && src[i] != '\0'; i++)
dest[i] = src[i];
while (i < n)
{
dest[i] = '\0';
i++;
}
return (dest);
}
