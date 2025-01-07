#include "shell.h"

/**
 * execute - Forks and executes a command.
 * @tokens: A double pointer to an element of
 * an array of string where the first string is the command.
 *
 * Return: 1 if the shell should continue,
 * 0 if the shell should exit.
 */
int execute(char **tokens)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork failed\n");
		return (1);
	}

	if (pid == 0)
	{
		if (execve(tokens[0], tokens, environ) == -1)
		{
			perror("execve failed\n");
			free_resources(tokens, NULL);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}

	return (1);
}
