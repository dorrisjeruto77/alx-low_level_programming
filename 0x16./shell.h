#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>

#define MAX_COMMAND_LENGHT 1024
#define MAX_ARGUMENTS 64
#define BUFFER_SIZE 1024
#define PROMPT " ($) "

/* for getline */
#define USE _GETLINE

/**
* @arg: access command-line arguments passed to a program when it is executed
* @argv:array of string char*
* @fname:program file name
* @token: user input
* @status :state of the process
* @size-t: number of bytes
*/

/* main.c */
*int main(void);
*void execute_command(char *command);

/* arguments.c */
*int main(int argc, char *argv[]);
*ssize_t _getline(char **lineptr, size_t *n, FILE * stream);

/* path.c */
*int char *find - file(const char *filename);
*int main(void);
*char *initializepath(char **pwd);

/*exit_builtin.c*/
*int on exit(void(*function)(int, void*), void *arg);

/* env_builtin.c */
*void execute_env(void);
*void execute_echo_home(void);
*void execute_pwd(void);
*void execute_export(char **args);
*void execute_unset(char **args);

/* buffer.c */
*char *my_getline(void);
*int main(void);

/* tokenizeinput.c */
*void tokenize(char *input, char *delimiter);
*int main(void);

/* exit_status.c */
*void _Exit(int status);

/* setenv.c */
*int _setenv(const char *name, const char *value, int overwrite);
*int _unsetenv(const char *name);
*void unset_env_variable(const char *variable);
*void execute_builtin_command(char **args, int num_args);
*int main(void);

/* cddir.c */
*int chdir(const char *path);
*char *get_current_dir_name(void);

/*vars.c*/
*void run_command(char *command)
* void run_commands(char *commands)
* int main(void)

/*info_t.c*/
* void execute_command(char *command);
*void handle_logical_operators(char *command);
*void interactive_mode(void);
*void non_interactive_mode(void);
*int main(int argc, char *argv[]);

/* alias.c */
*void printalias(const char *name, const char *program_name);
*int main(int argc, char *argv[]);

/* replacement.c */
*char *replace_variables(const char *command);
*int main(void);

/* comments.c */
*main(int argc char *argv[]);

/* input.c */
*int main(int argc, char *argv[]);
*void execute_command(const char *command);
*void execute_command(const char *command);
#endif /* SHELL_H */

