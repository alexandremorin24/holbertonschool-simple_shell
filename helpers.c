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

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: Pointer to the previously allocated memory block
 * @old_size: Size, in bytes, of the allocated space for ptr
 * @new_size: New size, in bytes, of the new memory block
 *
 * Return: Pointer to the newly allocated memory block, or NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
		{
			return (NULL);
		}
		return (new_ptr);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	for (i = 0; i < old_size && i < new_size; i++)
		((char *)new_ptr)[i] = ((char *)ptr)[i];

	free(ptr);
	return (new_ptr);
}
