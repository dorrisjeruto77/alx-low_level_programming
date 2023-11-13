#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * execute_command - Execute the given command.
 * @command: The command to execute.
 */
void execute_command(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *args[] = {"/bin/sh", "-c", command, NULL};

		if (execve("/bin/sh", args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}

/**
 * handle_logical_operators - Handle the logical operators in the command.
 * @command: The command to handle.
 */
void handle_logical_operators(char *command)
{
	const char *delimiter = "&&";
	char *token = strtok(command, delimiter);

	while (token != NULL)
	{
		int result = system(token);

		if (result != 0 && strstr(token, "||") == NULL)
			break;
		token = strtok(NULL, delimiter);
	}
}

/**
 * interactive_mode - Run the shell program in interactive mode.
 */
void interactive_mode(void)
{
	char buffer[BUFFER_SIZE];

	while (1)
	{
		printf("($) ");
		fgets(buffer, BUFFER_SIZE, stdin);

		buffer[strcspn(buffer, "\n")] = '\0';

		if (strcmp(buffer, "exit") == 0)
		{
			break;
		}

		handle_logical_operators(buffer);
	}
}

/**
 * non_interactive_mode - Run the shell program in non-interactive mode.
 */
void non_interactive_mode(void)
{
	char buffer[BUFFER_SIZE];

	while (fgets(buffer, BUFFER_SIZE, stdin))
	{
		buffer[strcspn(buffer, "\n")] = '\0';
		handle_logical_operators(buffer);
	}
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, or the exit status on failure.
 */
int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		interactive_mode();
	}
	else if (argc == 2 && strcmp(argv[1], "-c") == 0)
	{
		non_interactive_mode();
	}
	else
	{
		fprintf(stderr, "Usage: %s [-c]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

return (0);
}
