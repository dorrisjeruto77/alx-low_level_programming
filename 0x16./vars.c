#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

/**
 * run_command - Executes a single command.
 * @command: The command to execute.
 */
void run_command(char *command)
{
	char *arguments[MAX_ARGUMENTS];
	char *token;
	int arg_count = 0;

	token = strtok(command, " ");
	while (token != NULL && arg_count < MAX_ARGUMENTS - 1)
	{
		arguments[arg_count++] = token;
		token = strtok(NULL, " ");
	}
	arguments[arg_count] = NULL;

	pid_t pid = fork();

	if (pid == 0)
	{
		execve(arguments[0], arguments, NULL);
		_exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	else
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
}

/**
 * run_commands - Executes a series of commands separated by ';'.
 * @commands: The commands to execute.
 */
void run_commands(char *commands)
{
	char *token;

	token = strtok(commands, ";");
	while (token != NULL)
	{
		run_command(token);
		token = strtok(NULL, ";");
	}
}

/**
 * main - Entry point of the program.
 * Return: Always 0.
 */
int main(void)
{
	char input[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("Enter commands: ");
		fflush(stdout);

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n");
			break;
		}
			input[strcspn(input, "\n")] = '\0';

			run_commands(input);
	}

return (0);
}
