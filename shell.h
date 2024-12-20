#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

char *read_line(void);
char **split_line(char *line, char *delim);
int execute(char **tokens);
char *_getenv(const char *name);

#endif
