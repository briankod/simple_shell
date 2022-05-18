#include "main.h"

/**
 * get_path - function that finds the path.
 * @env: a global variable.
 * Return: path in tokens.
 */

char **get_path(char **env)
{
	char *find_path, **ts, *dlm;

	dlm = ":";
	find_path = env_path(env, "PATH");
	ts = _token(find_path, dlm);
	return (ts);
}