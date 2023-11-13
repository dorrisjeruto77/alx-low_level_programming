#include <stdio.h>

/**
* main - Entry point of the  program
* Return: Ailways  0
*/
int main(void)
{
	char command[100];

	while (1)
	{
		printf("Enter a command: ");
		fgets(command, sizeof(command), stdin);

		if (command[0] == '#')
		{
			continue;
		}

	}
	return (0);
}
