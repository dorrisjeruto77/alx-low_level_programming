#include "main.h"

/**
 * get_bit - Returns the value of a bit at agiven index
 * @index: this is the index, beginning from 0 of the bit you want to get
 *
 * @n: decimal number from which the bit is extracted.
 * Return: value of the bit at index or -1 if an error occured
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int get;

	if (index > 64)
		return (-1);
	get = n >> index;

	return (get & 1);
}
