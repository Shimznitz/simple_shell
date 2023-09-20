#include "shell.h"

/**
 * _mem_set - These fills memory with a constant byte
 * @s: Pointer to the memory area
 * @b: Byte to fill *s with
 * @n: This amount of bytes to be filled
 * Return: This (s)is a pointer to the memory area s
 */
char *_mem_set(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - It's frees a string of strings
 * @dd: Thses are string of strings
 */
void ffree(char **dd)
{
	char **a = dd;

	if (!dd)
		return;
	while (*dd)
		free(*dd++);
	free(a);
}

/**
 * _realloc - Reallocates a block of memory
 * @ptr: Pointer to previous malloc'ated block
 * @old_size: Byte size of previous block
 * @new_size: Byte size of new block
 *
 * Return: The  pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
