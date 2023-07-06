#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: the character to point
 * Return: 1 on success
 * On error, -1 is returned, and errno is set
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
