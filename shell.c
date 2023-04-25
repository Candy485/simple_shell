#include "shell.h"

/**
 * main - main method or the start of the program
 * @argc: command argument
 * @argv: command argument value
 * @env: environment (valid command)
 * Return: 0
*/
int main(int argc, char *argv[], char **env)
{
	if (argc == 1)
	prompt(argv, env);
	return (0);
}
/**
 * prompt - display command prompt and accept commands from user recursivly
 * @argv: argument passed
 * @env: environment variable
 * Return: nothing
*/
void prompt(char **argv, char **env)
{
	char *command = NULL;	/*command entered from the user*/
	int c, pStatus;	/*c: character counter, pStatus: child process status*/
	size_t n = 0;	/*n: address of character*/
	ssize_t num_char;	/*num_char: number of character entered and read*/
	char *arg[] = {NULL, NULL};	/*arg: argument value passed*/
	pid_t cldId;	/*cldId: child process*/

	while (1)
	{
		if (isatty(STDIN_FILENO))	/*if end of file*/
			printf("#cisfun$ ");
		num_char = getline(&command, &n, stdin);	/*read all line*/
		if (num_char < 0)
		{
			free(command);
			exit(127);
		}
		c = 0;
		while (command[c])
		{
			if (command[c] == '\n')	/*check enter key*/
				command[c] = 0;
			c++;
		}
		arg[0] = command;
		cldId = fork();	/*create child process, return -1 if it is failed*/
		if (cldId < 0)
		{
			free(command);
			exit(127);
		}
		else if (cldId == 0)
		{
			if (execve(arg[0], arg, env) < 0)	/*execute the command*/
				printf("%s No such file or directory\n", argv[0]);
		}
		else
			wait(&pStatus);	/*wait the child process*/
	}
}
