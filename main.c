#include "shell.h"

/**
 * main - This is an  entry point
 * @ac: Arguments  count
 * @av: Arguments  vector
 *
 * Return: On success 0, on error 1
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (fd)
			: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_ePuts(av[0]);
				_ePuts(": 0: Can't open ");
				_ePuts(av[1]);
				_e_putchar('\n');
				_e_putchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	populate_env_list(info);
	readHistory(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
