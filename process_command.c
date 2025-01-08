#include "shell.h"

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
		return (handle_exit(tokens));

	if (strcmp(tokens[0], "env") == 0)
		return (handle_env(tokens));

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
