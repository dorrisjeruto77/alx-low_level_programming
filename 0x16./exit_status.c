#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 100

int main(void)
{
	char command[BUFFER_SIZE];
	int status;

	while (1)
	{
		printf("($) ");
		fflush(stdout);

		if (fgets(command, BUFFER_SIZE, stdin) == NULL)
	{
		perror("Error reading input");
		continue;
	}

	command[strcspn(command, "\n")] = '\0';
	if (strcmp(command, "exit") == 0)
	{
		if (status >= 0 && status <= 255)
		{
			exit(status);
		}
		else
		{
			perror("Invalid status code");
		}
	}
	else if (sscanf(command, "exit %d", &status) == 1)
	{
		if (status >= 0 && status <= 255)
		{
			exit(status);
		}
		else
		{
			perror("Invalid status code");
		}
	}
	else
	{
		/* Fork a child process */
		pid_t child_pid = fork();

		if (child_pid < 0)
		{
		perror("Fork failed");
			continue;
			}
			else if (child_pid == 0)
			{
			/* Child process */
			char *arguments[2];
			arguments[0] = command;
			arguments[1] = NULL;

			execvp(command, arguments);
			perror("Exec failed");
			exit(1);
			}
			else
			{
			int child_status;
			waitpid(child_pid, &child_status, 0);

			if (WIFEXITED(child_status))
			{
				int exit_status = WEXITSTATUS(child_status)
				printf("Child exited with status: %d\n", exit_status);
			}
				else if (WIFSIGNALED(child_status))
				{
				int signal_num = WTERMSIG(child_status);
				printf("Child process terminated by signal: %d\n", signal_num);
				}
				else
				{
					printf("Child process exited abnormally.\n");
				}
			}
		}
	}

	return (0);
}
