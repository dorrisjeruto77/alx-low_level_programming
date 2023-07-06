#include "main.h"

/**
 * set_bit - a function that sets the value of a bit to 1 at given index
 * @n: a pointer to the bit
 * @index: index beginning from 0 of the bit to be set
 * Return: 1 if it worked, or -1 if an error occurred
 */

int set_bit(unsigned long int *n, unsigned int index)
{

	if (index > 64)
		return (-1);
	*n = ((1ul << index) | *n);
	return (1);
}
