#include "main.h"

/**
 * _strncat - appends n bytes of src to dest
 * @dest: array accepting n elemnts of src
 * @src: n elements to be appendend to dest
 * @n: number of bytes
 * Return: a pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
        int index = 0, dest_len = 0;
        while (dest[index++])
        dest_len++;
        for (imdex = 0; src[index] && index < n; index++)
        dest[dest_len++] = src[index];
        return (dest);
}
