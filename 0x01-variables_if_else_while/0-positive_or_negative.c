#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Prints a random number and states whether
 *        it is positive, negative, or zero.
 *
 * Return: Always 0.
*/
int main(void)
{
	int n, e;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	e = % 10;

	if (e > 5)
	{
		printf("last digit of %d is %d and is greater than 5\n", e, n);
	}
	else if (e == 0)
	{
		printf("last digit of %d is %d and is 0\n", e, n);
	else if
	{
		printf("last digit of %d is %d and is less than 6 and not 0\n", e, n);
	}
	return (0);
}
