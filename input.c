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
	size_t i = 0, j = 0;           /* Index for tokens */
	char **tokens = malloc(bufsize * sizeof(char *)); /* Allocate memory for tokens array */
	char *token;            /* Temporary pointer for each token */
	char **temp;

	if (!tokens) /* Check memory allocation */
	{
		perror("allocation error");
		return (NULL);
	}

	token = strtok(line, delim);
	while (token != NULL)
	{
		tokens[i] = strdup(token);
		if (!tokens[i])
		{
			perror("strdup error");
			for (j = 0; j < i; j++)
				free(tokens[j]);
			free(tokens);
			return (NULL);
	}
		i++;

		if (i >= bufsize)
		{
			bufsize += 64;
			temp = realloc(tokens, bufsize * sizeof(char *));
			if (!temp)
			{
				perror("reallocation error");
				for (j = 0; j < i; j++)
					free(tokens[j]);
				free(tokens);
				return (NULL);
			}
			tokens = temp;
		}
		token = strtok(NULL, delim);
	}

	tokens[i] = NULL;
	return (tokens);
}
