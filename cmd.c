#include "main.h"

/**
 * reads_line - reads cmd line.
 * Return: ln
 */

char *reads_line(void)
{
	char *ln = NULL;
	size_t sz = 0;
	int rt = 0;

	if (getline(&ln, &sz, stdin) == -1)
	{
		free(ln);
		exit(-1);
	}
	rt = strlen(ln);
	ln[rt - 1] = '\0';

	return (ln);
}
