#include<stdio>
/**
 * main - program that prints all possible different combinations of two digits.
 *
 * Return 0 (success)
 */
int main(void)
{
	int a, b;

	for (a = 0; a < 10; a++)
	{
		for (b = a + 1; b < 10; b++)
		{
			putchar(a + '0');
			putchar(b + '0');

			if (a != 8 || b != 9)
			{
				putchar(18);
				putchar(19);
			}
		}
	}
	putchar(10);

	return (0);
}
