#include "shell.h"

/**
 * _myExit - Exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Exits with an exit status
 * (0) if info.argv[0] != "exit"
 */

int _myExit(info_t *info)
{
	int exit_check;

	if (info->argv[1]) /* If there is an exit arguement */
	{
		exit_check = _err_atoi(info->argv[1]);
		if (exit_check == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_ePuts(info->argv[1]);
			_e_putchar('\n');
			return (1);
		}
		info->err_num = _err_atoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycdir - Changes the current directory of the process
 * @info: It's a structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: It is always 0
 */

int _mycdir(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getEnv(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getEnv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getEnv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getEnv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getEnv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_ePuts(info->argv[1]), _e_putchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getEnv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - Changes the current directory of the process
 * @info: Structure containing potential arguments used to maintain
 * constant function prototype.
 * Return: Always 0
 */

int _myhelp(info_t *info)
{
	char **args_array;

	args_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*args_array);
	return (0);
}
