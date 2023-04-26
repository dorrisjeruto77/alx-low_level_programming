#include <unistd.h>
#include "main.h"

/**
 * _islower - Check main
 * @c: An input character
 * _islower : check main
 * Description : check for alphabetic character.
 * Return: 1 if c is lowercase or 0 otherwise
 */

int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
