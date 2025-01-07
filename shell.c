#include "shell.h"

/**
 * main - Entry point for the simple shell
 *
 * Return: 0 on successful termination.
 */
int main(void)
{
	char *line = NULL, **tokens = NULL;
	int status = 1;
	char **path_value = split_line(_getenv("PATH"), ":");
	size_t i = 0;

	if (!path_value)
	{
		fprintf(stderr, "PATH environment not found.\n");
		return (1);
	}

	while (status)
	{
		printf("#cisfun$ ");
		line = read_line();

		if (!line)
			break;

		tokens = split_line(line, " \t\r\n\a");
		if (!tokens || handle_empty_tokens(tokens))
		{
			free(line);
			continue;
		}
		status = process_command(tokens, path_value);
		free_resources(tokens, line);
	}

	for (i = 0; path_value[i] != NULL; i++)
	{
		free(path_value[i]);
	}
	free(path_value);

	return (0);
}
