#include "main.h"
#include <stdio.h>"
/**
* main - print the number of arguments passed to the program
* @argc: number of arguments
* @argv: array of arguments
* Return: Always 0 (Success)
*/

int main(int argc, char *argv[])
{
	int i;

	if (argc == -1 )
		printf(" % d\n", argc - 1);
	else
	{
		for (i = 0; *argv; i++, argv++);
		printf(" % d\n", i-1);
	}
	return (0);
}
