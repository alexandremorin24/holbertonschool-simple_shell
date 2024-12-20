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
	char **path_value; /* Variable to hold the PATH environment variable */

	/* Get the PATH value at startup */
	path_value = split_line(_getenv("PATH"), ":");
	if (path_value = NULL)
		fprintf(stderr, "PATH environment not found.\n");

	while (status)
	{
		printf("$ "); /* Display the prompt */

		line = read_line(); /* Read a line of input from the user with getline */

		if (line == NULL) /* Handle EOF (Ctrl+D) */
		{
			printf("\n");
			break;
		}

		if (strcmp(line, "\n") == 0) /* Handle empty lines */
		{
			free(line);
			continue;
		}

		tokens = split_line(line, "\t\r\n\a");

		status = execute(tokens);

		free(line);
		free(tokens);
	}

	return (0);
}
