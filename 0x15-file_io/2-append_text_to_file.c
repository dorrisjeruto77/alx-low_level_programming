#include "main.h"
#include <string.h>

/**
 * append_text_to_file - appends text to a file if it exists
 * @filename: pointer to the name of the file
 * @text_content: text to be appended
 *
 * Return: 1 if success -1 on failure(file does not exist)
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, fw, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fd = open(filename, O_WRONLY | O_APPEND);
	fw = write(fd, text_content, len);

	if (fd == -1 || fw == -1)
		return (-1);

	close(fd);

	return (1);
}
