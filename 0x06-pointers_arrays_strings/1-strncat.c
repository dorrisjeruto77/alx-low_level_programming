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
        char *ptr = dest;
        while (*dest)
                dest++;
        while (*src && n-- > 0)
                *dest++ = *src++;
        *dest = '\0';
        return (ptr);
}
