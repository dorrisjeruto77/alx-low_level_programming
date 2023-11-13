#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

/**
 * replace_variables - Replaces variables in a command string
 * @command: The command string
 *
 * Return: The modified command string
 */
char *replace_variables(const char *command)
{
	char *result = malloc(strlen(command) * 3 + 1);
	char *position = strstr(command, "$$");
	int index = 0;

	while (position != NULL)
	{
		strncpy(&result[index], command, position - command);
		index += position - command;
		char pid[10];

		sprintf(pid, "%d", getpid());
		strncpy(&result[index], pid, strlen(pid));
		index += strlen(pid);
		command = position + 2;
		position = strstr(command, "$$");
	}

	strcpy(&result[index], command);
	command = result;
	result = malloc(strlen(command) * 3 + 1);
	position = strstr(command, "$?");
	index = 0;

	while (position != NULL)
	{
		strncpy(&result[index], command, position - command);
		index += position - command;
		char code[10];

		sprintf(code, "%d", 0);
		strncpy(&result[index], code, strlen(code));
		index += strlen(code);
		command = position + 2;
		position = strstr(command, "$?");
	}

	strcpy(&result[index], command);
	return (result);
}

/**
 * main - Entry point of the program
 *
 * Return: 0 on success, otherwise 1
 */
int main(void)
{
	char userInput[100];

	while (1)
	{
		printf("$ ");
		if (fgets(userInput, sizeof(userInput), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		userInput[strcspn(userInput, "\n")] = '\0';

		pid_t pid, wpid;
		int status;

		pid = fork();

		if (pid == 0)
		{
			if (execvp(args[0], args) == -1)
			{
				perror("lsh");
			}
		}
		exit(EXIT_FAILURE);
	}
		else if (pid < 0)
		{
			perror("lsh");
		}
		else
		{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		while
			(!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
		return (1);
