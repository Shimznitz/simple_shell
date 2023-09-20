#include "shell.h"

/**
 * _myEnv - Prints current environment
 * @info: It's a structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */

int _myEnv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getEnv - Gets value of environ variable
 * @info: It's a structure containing potential arguments. Used to maintain
 * @name: The env var name
 *
 * Return: This is the value
 */
char *_getEnv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *ptr;

	while (node)
	{
		ptr = starts_with(node->str, name);
		if (ptr && *ptr)
			return (ptr);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mySetEnv - Initializes new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: It is always 0
 */

int _mySetEnv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myUnsetEnv - It removes an environment variable
 * @info: It is a structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: It is always 0
 */

int _myUnsetEnv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - Populates the env linked list
 * @info: Struct containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */

int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
