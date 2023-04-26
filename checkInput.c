#include "shell.h"
/**
 * check_cmd - check file with correct dir
 * @cmd: supplied command
 * Return: check correct cmd
 */
char *check_cmd(char *cmd)
{
	DIR *dir = opendir("/bin/");
	char *temp, *cats;
	struct dirent *entity;

	if (dir == NULL)
		return (NULL);
	entity = readdir(dir);
	while (entity != NULL)
	{
		temp = entity->d_name;
		if (strcmp(temp, cmd) == 0)
		{
			cats = strcat("/bin/", cmd);
			closedir(dir);
			return (cats);
		}
		entity = readdir(dir);
	}
	closedir(dir);
	return (NULL);
}
/**
 * check_PATH - check path
 * @cmd: supplied command
 * Return: 1 for success
 */
int check_PATH(char *cmd)
{
	char *cmp = "/bin/", *ptr, *j;
	int i = 0, p = 0;

	ptr = malloc(sizeof(char) * 50);
	if (ptr == NULL)
	return (0);
	while (cmp[i] != '\0')
	{
	if (cmp[i] != cmd[i])
	{
	free(ptr);
	return (0);
	}
	i++;
	}
	while (cmd[i] != '\0')
	{
	ptr[p] = cmd[i];
	p++;
	i++;
	}
	ptr[p] = '\0';
	j = check_cmd(ptr);
	if (j != NULL)
	{
	free(ptr);
	return (1);
	}
	return (0);
}
/**
 * execute - execute fork
 * @cmd: string command user insert
 * @env: enviroment variable
 */
void execute(char **cmd, char *env[])
{
	pid_t child_id;
	int pStatus;

	child_id = fork();
	if (child_id < 0)
	{
		perror("Fail to create child process\n");
		exit(-1);
	}
	else if (child_id == 0)
	{
		if (execve(cmd[0], cmd, env) < 0)
			perror("./shell: No such file or directory\n");
	}
	else
		wait(&pStatus);
}
