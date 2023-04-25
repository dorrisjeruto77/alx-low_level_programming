#include<unistd.h>
/**
 * main - program that prints _putchar, followed by a new line.
 *_putchar - writes the character c to stdout
 * Return: 0 (success)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
