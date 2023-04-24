#include <stdio.h>

/**
 * main - program will  print single digit numbers of base from 0 - 10
 *
 * Description: The  program print all single digit numbers of base from 0 - 10
 *
 * Return: 0
 */

int main(void)
{
	int num;

	for (num = 0; num < 10; num++)
	{
		putchar(num % 10) + '0');
	}

	putchar('\n');

	return (0);
}
