#include "main.h"

/**
* print_alphabet_x10 -  prints 10 times the alphabet, in lowercase
*
* Return: void.
*/

void print_alphabet_x10(void)
{
	char i;
	int j = 0;

	for (j = 0; j < 10; j++)
	{
		for (i = 'a'; i <= 'z'; i++)
		{
			_putchar(i);
		}
		_putchar('\n');
	}
}
