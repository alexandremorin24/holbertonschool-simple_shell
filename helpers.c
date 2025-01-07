#include "shell.h"

/**
 * handle_empty_tokens - Handles empty tokens.
 * @tokens: Array of tokens.
 *
 * Return: 1 if the tokens are empty, otherwise 0.
 */
int handle_empty_tokens(char **tokens)
{
	if (tokens[0] == NULL)
	{
		free(tokens);
		return (1);
	}
	return (0);
}

/**
 * process_command - Processes a command.
 * @tokens: List of tokens of the command.
 * @path_value: List of paths in the PATH variable.
 *
 * Return: 1 if the command executes successfully, otherwise 0.
 */
int process_command(char **tokens, char **path_value)
{
	char *full_path;

	if (tokens == NULL || tokens[0] == NULL)
		return (1);

	if (strcmp(tokens[0], "exit") == 0)
		return (0);

	if (strcmp(tokens[0], "env") == 0)
	{
		print_env();
		return (1);
	}

	full_path = find_command(path_value, tokens[0]);
	if (full_path != NULL)
	{
		if (tokens[0] != full_path)
		{
			free(tokens[0]);
		}
		tokens[0] = full_path;
		return (execute(tokens));
	}
	else
	{
		fprintf(stderr, "Command not found: %s\n", tokens[0]);
	}

	return (1);
}

/**
 * print_env - Prints the environment variables.
 */
void print_env(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}

/**
 * free_resources - Frees the memory of allocated resources.
 * @tokens: Array of tokens.
 * @line: Read line.
 */
void free_resources(char **tokens, char *line)
{
	size_t i = 0;

	/* First, free the tokens */
	if (tokens != NULL)
	{
		for (i = 0; tokens[i] != NULL; i++)
		{
			free(tokens[i]);  /* Free each token */
		}
		free(tokens);  /* Free the token array */
	}

	/* Then, free the read line */
	if (line != NULL)
	{
		free(line);  /* Free the read line */
	}
}
