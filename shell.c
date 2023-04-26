#include "shell.h"

/**
 * main - main method or the start of the program
 * @argc: command argument
 * @argv: argument vectort
 * @env: environment (valid command)
 * Return: 0
*/
int main(int argc, char **argv, char **env)
{
	if (argc == 1)
		prompt(argv, env);
	return (0);
}
/**
 * accept_input - accept input until the user hit enter
 * @cmd: string input
 * Return: string command
 */
char *accept_input(char *cmd)
{
	char *str;
	int i = 0;
	
	str = malloc(8 * sizeof(char *));
	if (str == NULL)
		return (NULL);
	while (cmd[i])
	{
		if (cmd[i] == '\n')
			cmd[i] = 0;
		str[i] = cmd[i];
		i++;
	}
	return (str);
}
/**
 * prompt - display command prompt and accept commands from user recursivly
 * @argv: argument passed
 * @env: environment variable
 * Return: nothing
*/
void prompt(char *argv[], char **env)
{
	char **string;	/*command entered from the user*/
	int c = 0;	/*c: character counter, pStatus: child process status*/
	size_t n = 0;	/*n: address of character*/
	ssize_t num_char;	/*num_char: number of character entered and read*/
	char *arg, *ptr;	/*arg: argument value passed*/

	while (1)
	{
		if (isatty(STDIN_FILENO))	/*if end of file*/
			write(STDOUT_FILENO, "#cisfun$ ", 10);
		ptr = malloc(sizeof(char *) * n);
		if (ptr == NULL)
		{
			free(string);
			exit(1);
		}
		num_char = getline(&ptr, &n, stdin);	/*read all line*/
		if (num_char < 0)
		{
			free(string);
			exit(1);
		}
		if (*ptr != '\n')
		{
			string = _strtok(ptr);
			if (strcmp("exit", string[0]) == 0)
				break;
			c = 0;
			arg = check_cmd(string[0]);
			if (arg != NULL)
				string[0] = arg;
			c = check_PATH(string[0]);
			if (c == 1)
				execute(string, env);
			if (arg == NULL && c == 0)
				printf("%s: No such file or directory\n", argv[0]);
		}
	}
	free(arg);
}
