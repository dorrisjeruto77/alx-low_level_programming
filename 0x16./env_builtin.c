#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * execute_env - Executes the built-in env command
 */
void execute_env(void)
{
	char **env_ptr = environ;

	while (*env_ptr != NULL)
	{
		write(STDOUT_FILENO, *env_ptr, strlen(*env_ptr));
		write(STDOUT_FILENO, "\n", 1);
		env_ptr++;
	}
}

/**
 * execute_echo_home - Executes the built-in echo $HOME command
 */
void execute_echo_home(void)
{
	char *home = getenv("HOME");

	if (home != NULL)
	{
		write(STDOUT_FILENO, home, strlen(home));
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * execute_pwd - Executes the built-in pwd command
 */
void execute_pwd(void)
{
	char cwd[BUFFER_SIZE];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		write(STDOUT_FILENO, cwd, strlen(cwd));
		write(STDOUT_FILENO, "\n", 1);
	}
	else
	{
		perror("getcwd");
	}
}

/**
 * execute_export - Executes the built-in export command
 * @args: Array of arguments
 */
void execute_export(char **args)
{
	char *variable = strtok(args[1], "=");
	char *value = strtok(NULL, "=");

	if (variable != NULL && value != NULL)
	{
		if (setenv(variable, value, 1) != 0)
		{
			perror("setenv");
		}
	}
	else
	{
		write(STDOUT_FILENO, "Usage: export VARNAME=value\n", 28);
	}
}

/**
 * execute_unset - Executes the built-in unset command
 * @args: Array of arguments
 */
void execute_unset(char **args)
{
	char *variable = args[1];

	if (variable != NULL)
	{
		if (unsetenv(variable) != 0)
		{
			perror("unsetenv");
		}
	}
	else
	{
		write(STDOUT_FILENO, "Usage: unset VARNAME\n", 21);
	}
}
