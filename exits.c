#include "shell.h"

/**
 * *_strn_cpy - Copies the string
 * @dest: Destination string to be copied to
 * @src: Source string
 * @n: Amount of characters to be copied
 * Return: Concatenated string
 */
char *_strn_cpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * *_strn_cat - Concatenates two strings
 * @dest: First string
 * @src: Second string
 * @n: It is the amount of bytes to be maximally used
 * Return: It is the concatenated string
 */
char *_strn_cat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 * *_str_chr - Character in a string
 * @s: String to be parsed
 * @q: Character to look for
 * Return: (s) It is a pointer to the memory area s
 */
char *_str_chr(char *s, char q)
{
	do {
		if (*s == q)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
