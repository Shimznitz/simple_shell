#include "shell.h"

/**
 * _myHistory - It displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: It is a structure containing potential arguments. Used to maintain
 *  constant function prototype.
 *  Return: It is always 0
 */

int _myHistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - It sets the alias to string
 * @info: This is a parameter struct
 * @str: It is the string alias
 *
 * Return: It is always 0 on success, 1 on error
 */

int unset_alias(info_t *info, char *str)
{
	char *ptr, c;
	int ret;

	ptr = _str_chr(str, '=');
	if (!ptr)
		return (1);
	c = *ptr;
	*ptr = 0;
	ret = _delete_node_at_index(&(info->alias),
		_get_node_index(info->alias, _node_starts_with(info->alias, str, -1)));
	*ptr = c;
	return (ret);
}

/**
 * set_alias - It sets alias to the string
 * @info: This is the parameter struct
 * @str: It is the string alias
 *
 * Return: It is always 0 on success, 1 on error
 */

int set_alias(info_t *info, char *str)
{
	char *ptr;

	ptr = _str_chr(str, '=');
	if (!ptr)
		return (1);
	if (!*++ptr)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (addNodeEnd(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - It prints an alias string
 * @node: Alias node
 *
 * Return: Always 0, 1 on error
 */

int print_alias(list_t *node)
{
	char *ptr = NULL, *a = NULL;

	if (node)
	{
		ptr = _str_chr(node->str, '=');
		for (a = node->str; a <= ptr; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(ptr + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myAlias - It mimics the alias builtin (man alias)
 * @info: It is a structure containing potential arguments. Used to maintain
 *  constant function prototype.
 *  Return: It is always 0
 */

int _myAlias(info_t *info)
{
	int i = 0;
	char *ptr = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		ptr = _str_chr(info->argv[i], '=');
		if (ptr)
			set_alias(info, info->argv[i]);
		else
			print_alias(_node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
