#include "main.h"

/**
 * _strcat - appends src to dest
 * @dest: array to concat with src
 * @src: array to concat with dest
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
char *result = dest;
while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = '\0';
return (result);
}
