#include "main.h"

/**
 * executory - function that runs commands.
 * @argv: points to a string array.
 * Return: Always 0.
 */

int executory(char **argv)
{
	pid_t ret_value;
	int res;

	ret_value = fork();
	if (ret_value < 0)
	{
		perror("Error:");
	}
	else if (ret_value == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror(argv[0]);
			exit(1);
		}
	}
	else
	{
		wait(&res);
	}
	return (0);
}
