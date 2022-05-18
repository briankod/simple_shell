#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

char *reads_line(void);
char **_token(char *ln, char *dlm);
int executory(char **argv);
void _puts(char *str);
int _putchar(char c);
int _strlen(char *s);
char **get_path(char **env);
char *env_path(char **env, char *dir);
char *argstostr(char **a, char **new_str);
char *_strdup(char *str);
char *if_exists(char **env);
extern char **env;

#endif

