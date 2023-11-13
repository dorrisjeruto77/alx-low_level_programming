#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define PROMPT "($) "

/**
* main -Entry point
* Return: on success 0
*/

void execute_command(char *command);

int main(void)
{
	char buffer[BUFFER_SIZE];
	char *command;

	while (1)
	{
		printf(PROMPT);
		if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
		{
			break;
		}

		/* Remove trailing newline character */
		buffer[strcspn(buffer, "\n")] = '\0';

		command = strtok(buffer, " ");

		if (command != NULL)
		{
			if (strcmp(command, "exit") == 0)
			{
				break;
			}

			execute_command(command);
		}
	}

	return (0);
}

/**
* execute_command - Executes the given command
* @command: The command to execute
*/

void execute_command(char *command)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		/* Child process */
		if (execlp(command, command, (char *)NULL) == -1)
		{
			perror("execlp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		waitpid(pid, &status, 0);
	}
}
