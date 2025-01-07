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
	size_t bufsize = 64, i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;
	char **temp;

	if (!tokens)
	{
		perror("Memory allocation failed");
		return (NULL);
	}

	token = strtok(line, delim);
	while (token)
	{
		tokens[i] = strdup(token);
		if (!tokens[i])
		{
			perror("strdup error");
			free_resources(tokens, NULL);
			return (NULL);
		}
		i++;

	if (i >= bufsize)
	{
		bufsize += 64;
		temp = realloc(tokens, bufsize * sizeof(char *));
		if (!temp)
		{
			perror("realloc failed\n");
			free_resources(tokens, NULL);
			return (NULL);
		}
		tokens = temp;
	}
		token = strtok(NULL, delim);
	}
	tokens[i] = NULL;
	return (tokens);
}
