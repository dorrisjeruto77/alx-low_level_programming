#include "main.h"
#include <string.h>

/**
 *create_file - creates a file if does not exist and writes text to it
 *@filename: the file to be created
 *@text_content: pointer to a string
 *Return: 1 if succesful or -1 if failure
 */

int create_file(const char *filename, char *text_content)
{
	ssize_t fd, fw;
	int len;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		text_content = "";

	len = strlen(text_content);
	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	fw = write(fd, text_content, len);

	if (fd == -1 || fw == -1)
		return (-1);

	close(fd);
	return (1);
}
