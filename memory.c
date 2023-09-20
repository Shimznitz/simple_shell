#include "shell.h"

/**
 * bfree - Frees pointer, NULLs the address
 * @ptr: Address of the pointer to free
 *
 * Return: If freed 1, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
