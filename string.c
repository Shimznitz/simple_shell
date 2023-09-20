#include "shell.h"

/**
 * _strlen - Returns the length of a string
 * @b: String
 *
 * Return: The integer length of string
 */
int _strlen(char *b)
{
	int i = 0;

	if (!b)
		return (0);

	while (*b++)
		i++;
	return (i);
}

/**
 * _strcmp - Performs lexicogarphic comparison of two strangs.
 * @s1: 1st string
 * @s2: 2nd string
 *
 * Return: s1 < s2 if negative, s1 > s2 if positive, s1 ==s2 if zero
 */
int _strcmp(char *st1, char *st2)
{
	while (*st1 && *st2)
	{
		if (*st1 != *st2)
			return (*st1 - *st2);
		st1++;
		st2++;
	}
	if (*st1 == *st2)
		return (0);
	else
		return (*st1 < *st2 ? -1 : 1);
}

/**
 * starts_with - Checks if needle starts with haystack
 * @haystack: String to search
 * @needle: Substring to find
 *
 * Return: The address of next char of haystack or Viod
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - Concatenates two strings
 * @dest: Destination buffer
 * @src: A source buffer
 *
 * Return: The pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
