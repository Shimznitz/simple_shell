#include "shell.h"

/**
 * _list_len - length of linked list
 * @g: Pointer to first node
 *
 * Return: It's the size of list
 */
size_t _list_len(const list_t *g)
{
	size_t i = 0;

	while (g)
	{
		g = g->next;
		i++;
	}
	return (i);
}

/**
 * _list_to_strings - It returns an array of strings of the list->str
 * @head: It's a pointer to first node
 *
 * Return: It's an array of strings
 */
char **_list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * _print_list - Prints all elements of a list_t linked list
 * @g: Pointer to the first node
 *
 * Return: It's the size of list
 */
size_t _print_list(const list_t *g)
{
	size_t i = 0;

	while (g)
	{
		_puts(convert_number(g->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(g->str ? g->str : "(nil)");
		_puts("\n");
		g = g->next;
		i++;
	}
	return (i);
}

/**
 * _node_starts_with - Returns node whose string starts with prefix
 * @node: It's the pointer to list head
 * @prefix: It's a string to match
 * @q: It's the next character after prefix to match
 *
 * Return: It matches node or null
 */
list_t *_node_starts_with(list_t *node, char *prefix, char q)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((q == -1) || (*p == q)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * _get_node_index - Index of a node
 * @head: Pointer to list head
 * @node: Pointer to the node
 *
 * Return: It's the index of node or -1
 */
ssize_t _get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
