#include "main.h"

/**
 * @b: Pointer to a string containing the binary number
 *
 * binary_to_uint - handle conversion of binary to to unsigned int
 * Return: returns converted number
 */

unsigned int binary_to_uint(const char *b);
{
	unsigned int dec_val = 0;
	int i;

	if (!b)
		return (0);
	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		dec_val = 2 * dec_val + (b[i] - '0');
	}
	return (dec_val);
}
