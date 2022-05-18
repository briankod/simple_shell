#include "main.h"

/**
 * main - the primary function.
 * @ac: arguments' counter.
 * @av: arguments' values.
 * @env: global variable
 * Return: Always 0.
 */

int main(int ac, char **av, char **env)
{
	char *ln = NULL;
	char *dlm = "\t \a\n";
	char *cmd;
	char **ts;
	(void)ac;

	ts = get_path(env);

	signal(SIGINT, SIG_IGN);
	while (1)
	{
		ln = reads_line();
		av = _token(ln, dlm);
		cmd = argstostr(av, ts);
		if (cmd == NULL)
			executory(av);
		free(ln);
		free(av);
		free(cmd);
	}
	return (0);
}