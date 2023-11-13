#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COMMAND_LENGTH 1024

void execute_commands_from_file(const char *filename);

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line arguments
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		write(STDERR_FILENO, "Usage: ", 7);
		write(STDERR_FILENO, argv[0], strlen(argv[0]));
		write(STDERR_FILENO, " [filename]\n", 12);
		return (1);
	}

	char *filename = argv[1];

	execute_commands_from_file(filename);

	return (0);
}

/**
 * execute_command - Execute a command using system()
 * @command: The command to be executed
 */
void execute_command(const char *command)
{
	int status = system(command);

	if (status == -1)
	{
		char error_message[] = "Failed to execute the command.\n";

		write(STDERR_FILENO, error_message, sizeof(error_message) - 1);
	}
}

/**
 * execute_commands_from_file - Execute commands from a file
 * @filename: The name of the file containing commands
 *
 */
void execute_commands_from_file(const char *filename)
{
	int file = open(filename, O_RDONLY);

	if (file == -1)
	{
		char error_message[] = "Failed to open the file.\n";

		write(STDERR_FILENO, error_message, sizeof(error_message) - 1);
		return;
	}

	char command[MAX_COMMAND_LENGTH];

	ssize_t bytesRead;

	while ((bytesRead = read(file, command, sizeof(command))) > 0)
	{
		for (ssize_t i = 0; i < bytesRead; i++)
		{
			if (command[i] == '\n')
			{
				command[i] = '\0';
				execute_command(command);
			}
		}
	}

	close(file);
