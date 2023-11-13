#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH 1024

/**
 * exec_cd - Change the current working directory.
 * @arg: The directory path or argument.
 *
 * Return: 0 on success, 1 on failure.
 */
int exec_cd(char *arg)
{
	char lastdir[MAX_PATH] = {0};
	char curdir[MAX_PATH];
	char path[MAX_PATH];

	if (getcwd(curdir, sizeof(curdir)) == NULL)
	{
		perror("getcwd error");
		return (1);
	}
	if (arg == NULL)
	{
		arg = getenv("HOME");
	}

	if (!strcmp(arg, "-"))
	{
		if (*lastdir == '\0')
		{
			fprintf(stderr, "no previous directory\n");
			return (1);
		}
		arg = lastdir;
	}
	else
	{
		if (*arg == '~')
		{
			if (arg[1] == '/' || arg[1] == '\0')
			{
				snprintf(path, sizeof(path), "%s%s", getenv("HOME"), arg + 1);
				arg = path;
			}
			else
			{
				fprintf(stderr, "syntax not supported: %s\n", arg);
				return (1);
			}
		}
	}
	if (chdir(arg) != 0)
	{
		fprintf(stderr, "chdir: %s: %s\n", strerror(errno), path);
		return (1);
	}

	if (getcwd(curdir, sizeof(curdir)) == NULL)
	{
		perror("getcwd error");
		return (1);
	}

	strcpy(lastdir, curdir);
	return (0);
}
/**
 * @main - Entry point
 */
int main(int argc, char *argv[])
{
	if (argc > 2)
	{
		fprintf(stderr, "Usage: %s [DIRECTORY]\n", argv[0]);
		return (1);
	}
	char *dir = (argc == 2) ? argv[1] : NULL;
	return (exec_cd(dir);

