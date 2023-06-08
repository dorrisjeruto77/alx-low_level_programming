#include "main.h"

/**
 * set_bit - a function that sets
 * the value of a bit to 1 at given index
 * @n: a pointer to the bit
 * Return: 1 if it worked, or -1 if an error occurred
 */

int set_bit(unsigned long int *n, unsigned int index);
{
	if (index >= sizeof(unsigned long int) * 8
		return (-1);
	*n | = (lul << index);
}
