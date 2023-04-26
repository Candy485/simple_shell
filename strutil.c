#include "shell.h"
/**
 * _strtok - string separator with delimitor
 * @cmd: string command passed
 * Return: array list
 */
char **_strtok(char *cmd)
{
	char **arst, *pars;
	int i = 0, j = 0;
	arst = malloc(8 * sizeof(char *));
	if(arst == NULL)
	{
		perror("cant allocate space");
		exit(1);
	}
	pars = strtok(cmd, " ");
	while (pars != NULL)
	{
		while (pars[j])
		{
			if (pars[j] == '\n')
				pars[j] = '\0';
			j++;
		}
		arst[i] = pars;
		i++;
		j = 0;
		pars = strtok(NULL, " ");
	}
	arst[i] = NULL;
	return (arst);
}
