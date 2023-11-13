#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 * tokenize - Tokenizes the input string based on the delimiter
 * @input: Input string to be tokenized
 * @delimiter: Delimiter used for tokenization
 */
void tokenize(char *input, char *delimiter)
{
	char *token;
	char inputCopy[BUFFER_SIZE];
	int i = 0, j = 0;

	while (input[i] != '\0')
	{
		if (input[i] == delimiter[0])
		{
			inputCopy[j++] = '\n';
		}
		else
		{
			inputCopy[j++] = input[i];
	}
	i++;
}
	inputCopy[j] = '\0';

	token = strtok(inputCopy, "\n");

	while (token != NULL)
	{
		write(STDOUT_FILENO, "Token: ", strlen("Token: "));
		write(STDOUT_FILENO, token, strlen(token));
		write(STDOUT_FILENO, "\n", 1);
		token = strtok(NULL, "\n");
	}
}

/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
	char input[BUFFER_SIZE];
	char delimiter[] = " ";

	while (1)
	{
		write(STDOUT_FILENO, "($)", strlen("($)"));

		if (read(STDIN_FILENO, input, BUFFER_SIZE) == -1)
		{
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		tokenize(input, delimiter);
	}
	return (0);
}
