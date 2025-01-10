#include "shell.h"

/**
 * find_command - Searches for the full path of a command in a list of paths.
 * @paths: An array of strings, each representing a directory in the PATH.
 * @command: The command to locate (e.g., "ls").
 *
 * Return: A pointer to a dynamically allocated string containing the full path
 *         to the command if found and executable, or NULL otherwise.
 *         Prints an error message if the command exists but is not executable.
 */
char *find_command(char **paths, char *command)
{
	size_t i = 0, path_len, cmd_len;
	char *full_path = NULL;

	if (command[0] == '/' || command[0] == '.')
	{
		if (access(command, F_OK) == 0 && access(command, X_OK) == 0)
			return (command);  /* Return absolute path directly */
		fprintf(stderr, "Command '%s' not found or not executable\n", command);
		return (NULL);
	}
	while (paths[i] != NULL)
	{
		path_len = strlen(paths[i]); /* Length of the current path string */
		cmd_len = strlen(command);

		full_path = malloc(path_len + cmd_len + 2);
		if (!full_path)
		{
			perror("Memory allocation error");
			return (NULL);
		}
		strcpy(full_path, paths[i]);
		strcat(full_path, "/");
		strcat(full_path, command);
		if (access(full_path, F_OK) == 0) /* File exists */
		{
			if (access(full_path, X_OK) == 0) /* File is executable */
				return (full_path);
			/* If the file is not executable, print an error */
			fprintf(stderr, "bash: %s: permission denied\n", command);
			free(full_path);
			return (NULL);
		}
		free(full_path);
		full_path = NULL;
		i++;
	}
	fprintf(stderr, "bash: %s: command not found\n", command);
	return (NULL);
}
