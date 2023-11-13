#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * printalias - Print aliases based on the specified name
 * @name: Name of the alias to search for (NULL to print all aliases)
 * @program_name: Name of the program (equivalent to argv[0])
 */
void printalias(const char *name, const char *program_name)
{
	Alias aliases[] = {
		{"c", "clear"},
		{"ll", "ls -la"},
		{"g", "git"},
		{"mv", "move"},
	};
	int numAliases = sizeof(aliases) / sizeof(Alias);

	if (name == NULL)
	{

		for (int i = 0; i < numAliases; i++)
		{
			printf("%s='%s'\n", aliases[i].name, aliases[i].value);
		}
	}
	else
	{
		int found = 0;

		for (int i = 0; i < numAliases; i++)
		{
			if (strcmp(name, aliases[i].name) == 0)
			{
				printf("%s='%s'\n", aliases[i].name, aliases[i].value);
				found = 1;
				break;
			}
		}
		if (!found)
		{
			fprintf(stderr, "%s: Alias '%s' not found.\n", program_name, name);
			exit(1);
		}
	}
}

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		printalias(argv[1], argv[0]);
	}
	else
	{
		printalias(NULL, argv[0]);
	}

return (0);
}
