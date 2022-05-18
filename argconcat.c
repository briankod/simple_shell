#include "main.h"

/**
 * _strcat - check the code.
 * @dest: an input string.
 * @src: an input string.
 * Return: a pointer to the resulting string dest.
 */
char *_strcat(char *dest, char *src)
{
	char *temp = dest;

	while (*dest)
		dest++;

	while (*src)
		*dest++ = *src++;

	*dest = '\0';
	return (temp);
}

/**
 * argstostr - a function that concatenates all arguments of your program.
 * @a: an array char
 * @new_str: array containing arguments
 * Return: tt or null
 */

char *argstostr(char **a, char **new_str)
{
	char *tt, **ct;
	int i = 0, n, p;
	struct stat st;

	while (new_str[i])
	{
		tt = malloc(60);
		_strcat(tt, new_str[i]);
		_strcat(tt, "/");
		_strcat(tt, a[0]);

		if (stat(tt, &st) == 0)
		{
			for (p = 0; a[p] != NULL; p++)
				;
			ct = malloc(sizeof(char *) * (p + 1));
			ct[p] = NULL;
			ct[0] = _strdup(tt);

			for (n = 1; a[n]; n++)
				ct[n] = _strdup(a[n]);
			executory(ct);
			return (tt);
		}
		free(tt);
		i++;
	}
	return (NULL);
}
