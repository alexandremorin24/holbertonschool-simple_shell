#include "shell.h"

char *read_line(void)
{
	char *buffer = NULL;
	size_t buffsize = 0;

	if (getline(&buffer, &buffsize, stdin) == -1)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char **split_line(char *line, char *delim)
{
	size_t bufsize = 64;    /* Initial size for tokens array */
	size_t i = 0;           /* Index for tokens */
	char **tokens = malloc(bufsize * sizeof(char *)); /* Allocate memory for tokens array */
	char *token;            /* Temporary pointer for each token */

	if (!tokens) /* Check memory allocation */
	{
		perror("allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, delim);
	while (token != NULL)
	{
		tokens[i] = token;

		i++;

		if (i >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("reallocation error");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, delim);
	}

	tokens[i] = NULL;
	return (tokens);
}
