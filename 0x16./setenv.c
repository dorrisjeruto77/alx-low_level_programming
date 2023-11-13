#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ARGS 3
#define MAX_ARG_LENGTH 100

char **get_envron(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}
	return (info->environ);
}


/**
 * set_env_variable - Initialize a new environment variable
 * @variable: The name of the environment variable
 * @value: The value to be assigned to the environment variable
 *
 * Return: Always 0
 */
void set_env_variable(const char *variable, const char *value)
{
	if (setenv(variable, value, 1) != 0)
	{
		fprintf(stderr, "Failed to set environment variable.\n");
	}
}

/**
 * unset_env_variable - Remove an environment variable
 * @variable: The name of the environment variable to be removed
 *
 * Return: void
 */
void unset_env_variable(const char *variable)
{
	if (unsetenv(variable) != 0)
	{
		fprintf(stderr, "Failed to unset environment variable.\n");
	}
}

/**
 * execute_builtin_command - Execute the builtin commands
 * @args: The arguments passed to the command
 * @num_args: The number of arguments
 *
 * Return: void
 */
void execute_builtin_command(char **args, int num_args)
{
	if (strcmp(args[0], "setenv") == 0)
	{
		if (num_args == 3)
		{
			set_env_variable(args[1], args[2]);
		}
		else
		{
			fprintf(stderr, "Invalid setenv command syntax.\n");
		}
	}
	else if (strcmp(args[0], "unsetenv") == 0)
	{
		if (num_args == 2)
		{
			unset_env_variable(args[1]);
		}
		else
		{
			fprintf(stderr, "Invalid unsetenv command syntax.\n");
		}
	}
	else if (strcmp(args[0], "environment") == 0)
	{
		print_environment();
	}
	else
	{
		fprintf(stderr, "Unknown command: %s\n", args[0]);
	}
}

/**
 * main - Entry point of the program
 *
 * Return: 0 on success
 */
int main(void)
{
	char input[MAX_ARG_LENGTH];
	char *args[MAX_ARGS];
	int num_args;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("($) ");
		}

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}

		/* Tokenize the input */
		num_args = 0;
		args[num_args] = strtok(input, " \n");
		while (args[num_args] != NULL && num_args < MAX_ARGS - 1)
		{
			num_args++;
			args[num_args] = strtok(NULL, " \n");
		}

		if (args[0] != NULL)
		{
			execute_builtin_command(args, num_args);
		}
	}

	return (0);
}
