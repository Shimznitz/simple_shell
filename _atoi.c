#include "shell.h"

/**
 * interactive - If the shell is in interactive mode, it returns a true value
 * @info: The struct address
 *
 * Return: 1 if interactive mode, 0 if not
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delimtr - CAhecks if the character is a delimeter
 * @c: Character to check
 * @delimtr: Delimeter string
 * Return: 1 if true, 0 if false
 */

int is_delimtr(char c, char *delimtr)
{
	while (*delimtr)
		if (*delimtr++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - It checks for the alphabetic character
 * @q: Character to input
 * Return: 1 if c is an alphabet, 0 otherwise
 */

int _isalpha(int q)
{
	if ((q >= 'a' && q <= 'z') || (q >= 'A' && q <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - Converts a string to an integer
 * @c: the string is to be converted
 * Return: 0 if there are no numbers in the string, converted number otherwise
 */

int _atoi(char *c)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; c[i] != '\0' && flag != 2; i++)
	{
		if (c[i] == '-')
			sign *= -1;

		if (c[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (c[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
