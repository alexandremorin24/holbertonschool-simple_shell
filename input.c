#include "shell.h"

/**
 * read_line - Reads a line of input from stdin.
 *
 * Return: A pointer to the buffer containing the line read,
 *         or NULL if an error occurs or EOF is encountered.
 */
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

/**
 * split_line - Splits a line into tokens based on a delimiter.
 * @line: The line to split into tokens.
 * @delim: The delimiter used to split the line.
 *
 * Return: An array of strings (tokens),
 *         or NULL in case of memory allocation failure.
 */
char **split_line(char *line, char *delim)
{
	size_t bufsize = 64;
	size_t i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens) /* Check memory allocation */
	{
		perror("allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, delim);
	while (token)
	{
		/* Allocate memory for each token */
		tokens[i] = malloc(strlen(token) + 1);
		if (!tokens[i])
		{
			perror("allocation error for token");
			exit(EXIT_FAILURE);
		}

		strcpy(tokens[i], token); /* Copy the token to the tokens array */
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
