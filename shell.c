#include "shell.h"

/**
 * main - Entry point for the simple shell
 *
 * Return: 0 on successful termination.
 */
int main(void)
{
	char *line, **tokens;
	int status = 1;
	char **path_value = split_line(_getenv("PATH"), ":");

	if (!path_value)
	{
		fprintf(stderr, "PATH environment not found.\n");
		return (1);
	}

	while (status)
	{
		printf("#cisfun$ ");
		line = read_line();

		if (line == NULL)
			break;

		tokens = split_line(line, " \t\r\n\a");

		if (handle_empty_tokens(tokens))
			continue;

		status = process_command(tokens, path_value);

		free_resources(tokens, line);
	}

	free(path_value);
	return (0);
}
