#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/**
 * main - Entry point
 * exit_builtin - Built-in function for the "exit" command
 * _getline - reads the line of  input from a file.
 * Return: Always 0.
 */
int exit_builtin(void)
{
	return (0);
}

int main(void)
{
	char *command = NULL;
	size_t bufsize = 0;
	ssize_t bytes_read;

	while (1)
	{
		printf("$ ");
		bytes_read = _getline(&command, &bufsize, stdin);
	if (bytes_read == -1)
	{
		perror(__FILE__);
		exit(EXIT_FAILURE);
	}

		if (command[bytes_read - 1] == '\n')
		command[bytes_read - 1] = '\0';

		if (strcmp(command, "exit") == 0)
		{
			free(command);
			exit(exit_builtin());
		}
		free(command);
	}
		return (0);
	}
