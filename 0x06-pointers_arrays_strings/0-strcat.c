#include "main.h"
#include <stdio.h>
/**
 * _strcat - concat 2 string
 * @dest:char
 * @src:char
 * Return:char
 */
char *_strcat(char *dest, char *src)
{
int a = -1; i;
while (dest[i++])
for (i = 0; dest[i] != '\0'; i++);
do
{
          a++;
          dest[i] = src[a];
          i++;
}
while (src[a] != '\0');
return (dest);
}
