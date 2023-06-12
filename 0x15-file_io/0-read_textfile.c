#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads n bytes of a file and prints the bytes
 * @filename: pointer to the file
 * @letters: number of bytes to be read
 * Return: 0 if the system calls fail
 * The number of bytes read and printed
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t o, r, w;
	char *buffer;

	int bufferl;
	buffer = 0;

	if (filename == NULL)
		return (0);

	o = open(filename, O_RDONLY);
	r = read(o, buffer, letters);
	w = write(STDOUT_FILENO, buffer, r);

	if (o == -1 || r == -1 || w == -1)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(o);

	return (w);
}
