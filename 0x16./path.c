#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/**
 * initializepath - Initialize the path variable
 *
 * @pwd: Pointer to pwd (unused in this context)
 *
 * Return: Value of the path
 */
char *initializepath(char **pwd)
{
	(void)pwd;
	return ("PATH");
}

/**
 * find_file - Find a file in the PATH
 *
 * @filename: Name of the file to find
 *
 * Return: Path to the file if found, otherwise NULL
 */
char *find_file(const char *filename)
{
	char *path = initializepath(NULL);

	if (path == NULL)
	return (NULL);

	 char *dir 
	struct stat st;

	dir = strtok(path, ":");
	while (dir != NULL)
	{
		char *filepath = malloc(strlen(dir) + strlen(filename) + 2);
	if (filepath == NULL)
	{
		free(path);
		return (NULL);
	}

	sprintf(filepath, "%s/%s", dir, filename);

	if (stat(filepath, &st) == 0)
	{
		free(path);
		return (filepath);
	}

		free(filepath);
		dir = strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char *command = NULL;
	char *path = NULL;
	char prompt[] = "($) ";
	size_t bufsize = 0;

	while (1)
	{
	printf("%s", prompt);
	command = NULL;
	bytes_read = getline(&command, &bufsize, stdin) 

	if (strcmp(command, "exit\n") == 0)
	{
		free(command);
		break;
	}

	command[strcspn(command, "\n")] = '\0';

	path = find_file(command);
	if (path != NULL)
	{
		printf("%s\n", path);
	}
	else
	{
		printf("Command '%s' not found.\n", command);
	}

	free(path);
	free(command);
	}

	return (0);
}
