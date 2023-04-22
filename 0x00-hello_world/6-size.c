#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (success)
 */

int main(void)
{
	printf("Size of char: %u  byte(s)\n", sizeof(char));
	printf("Size of an int:	%u byte(s)\n", sizeof(int));
	printf("Size of long int: %u byte(s)\n", sizeof(long int));
	printf("Size of long long int: %u byte(s)\n", sizeof(long long int));
	printf("size of a float: %u byte(s)\n", sizeof(float));
	return (0);
}
