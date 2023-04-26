#include <unistd.h>
#include "main.h"

/**
 * print_alphabet - prints the english alphabet from a-z.
 * Return: void
 *
 */
void print_alphabet(void)
{
	char c;

	for (c = 'a'; c <= 'z'; c++)
	{
		_putchar(c);
	}
	_putchar('\n');
}
