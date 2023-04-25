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

void prompt(char **argv, char **env);
#endif
