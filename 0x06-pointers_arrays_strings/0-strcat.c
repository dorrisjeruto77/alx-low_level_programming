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
          int i = 0; j = 0;
          while (dest[i++])
                    j++;
          for (i = 0; src[i]; i++)
          {
                  dest[j++] = src[i];
          }
          return (dest);
}
