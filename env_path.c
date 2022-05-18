#include "main.h"

/**
 * len - function that checks the equals sign.
 * @s: a char
 * Return: s
 */

char *len(char *s)
{
	int i;

	for (i = 0; s[i] != '='; i++)
		;
	return (s + i + 1);
}

/**
 * _strcmp - check the code.
 * @s1: an input string.
 * @s2: an input string.
 * Return: The difference s1 - s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++, s2++;
	}
	return (*s1 - *s2);
}

/**
 * env_path -  gets path in env
 * @env: a global var
 * @dir: a char
 * Return: NULL or last
 */

char *env_path(char **env, char *dir)
{
	int i = 0, j = 0;
	char *var, *last;

	while (env[j])
	{
		var = malloc(1024);

		while (env[j][i] != '=')
		{
			var[i] = env[j][i];
			i++;
		}
		if (_strcmp(var, dir))
		{
			last = len(env[j]);
			free(var);
			return (last);

		}
		free(var);
		j++;
	}
	return (NULL);
}