#include "shell.h"

/**
 * main - Entry point for the simple shell
 *
 * Return: 0 on successful termination.
 */

int main(void)
{
	char *line; /* Pointer to hold the user input */
	char **tokens;    /* Array to store the tokens */
	int status = 1; /* Status to control the main loop (1 = running, 0 = exit) */
	char *full_path;   /* Pointer to store the result of find_command */
	char **path_value; /* Variable to hold the PATH environment variable */
	size_t i = 0;
	/* Get the PATH value at startup */

	path_value = split_line(_getenv("PATH"), ":");
	if (path_value == NULL)
		fprintf(stderr, "PATH environment not found.\n");

	while (status)
	{
		printf("#cisfun$ "); /* Display the prompt */

		line = read_line(); /* Read a line of input from the user with getline */

		if (line == NULL) /* Handle EOF (Ctrl+D) */
		{
			printf("\n");
			break;
		}

		tokens = split_line(line, " \t\r\n\a");

		if (tokens[0] == NULL) /* Handle empty tokens */
		{
			free(tokens);
			continue;
		}

		if (tokens[0][0] == '/')
			full_path = tokens[0];
		else 
			full_path = find_command(path_value, tokens[0]);

		if (full_path)
		{
			tokens[0] = full_path;
			status = execute(tokens);
		}
		free(tokens);
	}

	while (path_value[i] != NULL)
	{
		free(path_value[i]);
		i++;
	}
	free(path_value);
	return (0);
}
