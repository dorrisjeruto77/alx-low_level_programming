#include <stdio.h>
/**
 * main - start
 *
 * description - print the size of data types
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	printf("Size of char: %d  byte(s)\n", sizeof(char));
	printf("Size of an int:	%d byte(s)\n", sizeof(int));
	printf("Size of long int: %d byte(s)\n", sizeof(long int));
	printf("Size of long long int: %d byte(s)\n", sizeof(long long int));
	printf("size of a float: %d byte(s)\n", sizeof(float));
	return (0);
}
