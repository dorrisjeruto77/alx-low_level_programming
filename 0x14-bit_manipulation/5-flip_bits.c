#include"main.h"

/**
 * flip_bits - counts the number of bits to change
 * @n: first number
 * @m: second number
 * Return: number of bits to change
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int count = 0;

	unsigned long int result result = n ^ m;

	while (result)
	{
		count += result &1;
		result >>= 1;
	}
	return (count);
}
