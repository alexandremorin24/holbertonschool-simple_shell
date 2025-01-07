#include "shell.h"

/**
 * _getenv - Retrieves the value of an environment variable.
 * @name: The name of the environment variable to retrieve.
 *
 * Return: A pointer to the value of the environment variable,
 * or NULL if the environment variable is not found.
 */
char *_getenv(const char *name)
{
	size_t len = strlen(name);
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		if (strncmp(*env, name, len) == 0 && (*env)[len] == '=')
		{
			return (&((*env)[len + 1]));
		}
	}
	return (NULL);
}
