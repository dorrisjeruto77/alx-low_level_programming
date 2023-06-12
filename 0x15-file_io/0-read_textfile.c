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
	ssize_t fd;
	ssize_t w;
	ssize_t t;
	char *buf;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);

	return (w);
}
