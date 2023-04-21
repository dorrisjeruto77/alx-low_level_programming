#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	char c;
	int i;
	long int li;
	long long int lli;
	float f;

	printf("Size of char: %lu  byte(s)\n", sizeof(c));
	printf("Size of an int:	%lu byte(s)\n", sizeof(i));
	printf("Size of long int: %lu byte(s)\n", sizeof(li));
	printf("Size of long long int byte(s)\n", sizeof(lli));
	printf("size of a float: %lu byte(s)\n", sizeof(f));
	return (0);
}
