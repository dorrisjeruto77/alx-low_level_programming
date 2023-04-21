#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	short a;
	long b;
	long long c;
	long long d;

	printf("Size of a short: %lu byte(s)\n", sizeof(a));
	printf("Size of long: %lu byte(s)\n", sizeof(b));
	printf("Size of long long: %lu byte(s)\n", sizeof(c));
	printf("Size of long double: %lu byte(s)\n", sizeof(d));
	return (0);
}
