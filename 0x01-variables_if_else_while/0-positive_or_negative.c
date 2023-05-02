#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - Prints if number is positive, zero or negative
 * Return: 0  (success)
 */
int main(void)
{
	int n;

	srand(time(NULL));
	n = rand() % 21 - 10;

	printf("%d\n", n);
	if (n > 0)
		printf("is positive\n");
	else if (n == 0)
		printf("%d is zero\n");
	else
		printf("%d is negative\n");
	return (0);
}
