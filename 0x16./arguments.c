#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64

/**
 * main - Entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{

	char command 1024;
	char *arguments 64;

	while (1)
	{
		printf("($) ");
		getline(char (*)[1024], sizeof(command), stdin);

		command[strcspn(command, "\n")] = '\0';

	if (strcmp(command, "exit") == 0)
	{
		break;
	}
	char *token = strtok(command, " ");
	int argIndex = 0;

	while (token != NULL && argIndex < MAX_ARGUMENTS - 1)
	{
		arguments[argIndex] = token;
		token = strtok(NULL, " ");
		argIndex++;
	}
		arguments[argIndex] = NULL;

		pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{

		execvp(arguments[0], arguments);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
return (0);
}

/**
 * _getline - Read a line from input stream.
 * @lineptr: Pointer to the buffer storing the line.
 * @n: Pointer to the size of the buffer.
 * @stream: Input stream.
 * Return: Number of characters read, or -1 on failure.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t numRead;
	size_t len = 0;
	char *line = NULL;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}
		numRead = getline(&line, &len, stream);
	if (numRead != -1)
	{
		*lineptr = line;
		*n = len;
	}
return (numRead);
}
