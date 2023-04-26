#ifndef SHELL_HEADER
#define SHELL_HEADER

#include <stdio.h>
#include <unistd.h> /* for fork, execve*/
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h> /* for type pid */
#include <sys/wait.h> /* for wait */
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>

char *accept_input(char *cmd);
void prompt(char **argv, char **env);
char **_strtok(char *cmd);
char *check_cmd(char *cmd);
int check_PATH(char *cmd);
void execute(char **cmd, char *env[]);
#endif
