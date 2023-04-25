#include<stdio.h>
/**
 * main - program that prints _putchar, followed by a new line.
 *
 * Return: 0 (success)
 */
int main(void)
{
	char c[] = "putchar";
	int i;

	for (i = 0; i < 9; i++)
	{
		_putchar(c[i]);
	}
	_putchar('\n');
	return (0);
}
