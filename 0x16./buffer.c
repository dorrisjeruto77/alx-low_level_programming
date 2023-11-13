#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 * my_getline - Custom implementation of getline
 *
 * Return: Pointer to the read line or NULL on error or end of input
 */
char *my_getline(void)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_pos;
	static int buffer_size;

	char *line = NULL;
	int line_length = 0;

	while (true)
	{
		/* If buffer is empty or fully read */
		if (buffer_pos >= buffer_size)
		{
			buffer_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			buffer_pos = 0;

			if (buffer_size <= 0)
				break;
		}

		/* Search for newline character in the buffer */
		while (buffer_pos < buffer_size)
		{
			if (buffer[buffer_pos] == '\n')
			{

				buffer_pos++;
				break;
			}

			/* Copy character to the line */
			line = realloc(line, (line_length + 1) * sizeof(char));
			line[line_length++] = buffer[buffer_pos++];
		}

		if (buffer_pos >= buffer_size)
			continue;
		else
			break;
	}

	if (line != NULL)
	}

int main(void)
{
	char *line;

	while (true)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		line = my_getline();

		if (line == NULL)
		{

			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		if (line[0] != '\0')
		{
			write(STDOUT_FILENO, line, strlen(line));
			write(STDOUT_FILENO, "\n", 1);
		}

		free(line);
	}

	return (0);
}
