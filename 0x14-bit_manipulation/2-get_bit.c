#include "main.h"

/**
 * get_bit - a function to be returned
 * @index: this is the index, beginning from 0 of the bit you want to get
 *
 * @n: the bit
 * Return: value of the bit at index or -1 if an error occured
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int get;

	if (index > 16)
		return (-1);
	get = n >> index;

	return (get & 1);
}
