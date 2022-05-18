#include "main.h"

/**
 * _alloc - reallocates memory
 * @p: void variable pointer
 * @prev: integer input
 * @pres: integer input
 * Return: NULL
 */

void *_alloc(void *p, unsigned int prev, unsigned int pres)
{

	char *n;
	unsigned int i;

	if (p == NULL)
	{
		n = malloc(pres);
		return (n);
	}

	if (pres == 0 && p != NULL)
	{
		free(p);
		return (NULL);
	}

	if (pres == prev)
		return (p);

	n = malloc(pres);

	if (n == NULL)
		return (NULL);

	for (i = 0; i < prev; i++)
	{
		n[i] = ((char *)p)[i];
	}

	free(p);

	return (n);
}

/**
 * _token - function forms tokens
 * @ln: an input string
 * @dlm: an input string
 * Return: double pointer
 */

char **_token(char *ln, char *dlm)
{
	char **t;
	int bf = 1024, i = 0;

	t = malloc(sizeof(char *) * bf);
	if (!t)
		exit(99);

	t[i] = strtok(ln, dlm);
	i++;
	while (1)
	{
		t[i] = strtok(NULL, dlm);
		if (i >= bf)
		{
			bf += bf;
			t = _alloc(t, bf, bf * (sizeof(char *)));
			if (!t)
				exit(98);
		}
		if (t[i] == NULL)
			break;
		i++;
	}
	return (t);
}