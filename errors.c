#include "shell.h"

/**
 * _ePuts - Prints an input string
 * @str: String to print
 *
 * Return: Nothing
 */

void _ePuts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _e_putchar - Writes the character c to stderr
 * @q: Character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _e_putchar(char q)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (q == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (q != BUF_FLUSH)
		buf[i++] = q;
	return (1);
}

/**
 * _put_fd - Writes the character c to given fd
 * @q: Character to print
 * @fd: Filedescriptor
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _put_fd(char q, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (q == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (q != BUF_FLUSH)
		buf[i++] = q;
	return (1);
}

/**
 * _puts_fd - Prints an input string
 * @str: String to be printed
 * @fd: Filedescriptor
 *
 * Return: It is the number of chars put
 */

int _puts_fd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
