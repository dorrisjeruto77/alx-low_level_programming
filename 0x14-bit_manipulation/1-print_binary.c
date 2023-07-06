#include "main.h"

/**
 * @n: the decimal number to be printed in binary.
 * print_binary - prints the binary representation of a decimal  number
 *
 */

void print_binary(unsigned long int n)
{
	if (n > 1)
		print_binary(n >> 1);
	_putchar((n & 1) + '0');
}
