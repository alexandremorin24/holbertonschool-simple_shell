#include "shell.h"

/**
 * handle_exit - Handles the exit command.
 * @tokens: List of tokens of the command.
 *
 * Return: 0 to indicate the shell should exit.
 */
int handle_exit(char **tokens)
{
	(void)tokens;  /* Suppress unused parameter warning */
	return (0);
}

/**
 * handle_env - Handles the env command.
 * @tokens: List of tokens of the command.
 *
 * Return: 1 to indicate the command was handled.
 */
int handle_env(char **tokens)
{
	(void)tokens;
	print_env();
	return (1);
}
