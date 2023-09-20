#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - A singly linked list
 * @num: It's the number field
 * @str: It's a string
 * @next: It points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - It contains pseudo-arguements to pass into a function,
 * allowing uniform prototype for function pointer struct
 * @arg: It's a string generated from getline containing arguements
 * @argv: It's an array of strings generated from arg
 * @path: It's a string path for the current command
 * @argc: It's the argument count
 * @line_count: It's the error count
 * @err_num: It's the error code for exit()s
 * @linecount_flag: if it's on count this line of input
 * @fname: It's the program filename
 * @env: It's a linked list local copy of environ
 * @environ: The custom modified copy of environ from LL env
 * @history: It's the history node
 * @alias: It's the alias node
 * @env_changed: It's on if environ was changed
 * @status: It's the return status of the last exec'd command
 * @cmd_buf: The address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: The CMD_type ||, &&, ;
 * @readfd: It's the fd from which to read line input
 * @histcount: It is the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* a pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct builtin - It contains a builtin string and related function
 * @type: It is the builtin command flag
 * @func: It is the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* loophsh.c */
int loophsh(char **);

/* toem_parser.c */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* toem_errors.c */
void _ePuts(char *);
int _e_putchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* toem_string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* toem_string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* toem_shloop.c */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/* toem_tokenizer.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* toem_exits.c */
char *_strn_cpy(char *, char *, int);
char *_strn_cat(char *, char *, int);
char *_str_chr(char *, char);

/* toem_history.c */
char *getHistoryFile(info_t *info);
int writeHistory(info_t *info);
int readHistory(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumberHistory(info_t *info);

/* toem_realloc.c */
char *_mem_set(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* toem_memory.c */
int bfree(void **);

/* toem_atoi.c */
int interactive(info_t *);
int is_delimtr(char, char *);
int _isalpha(int);
int _atoi(char *);

/* toem_errors1.c */
int _err_atoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* toem_builtin.c */
int _myExit(info_t *);
int _mycdir(info_t *);
int _myhelp(info_t *);

/* toem_builtin1.c */
int _myHistory(info_t *);
int _myAlias(info_t *);

/*toem_getline.c */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/* toem_getinfo.c */
void clearinfo(info_t *);
void setinfo(info_t *, char **);
void freeinfo(info_t *, int);

/* toem_environ.c */
char *_getEnv(info_t *, const char *);
int _myEnv(info_t *);
int _mySetEnv(info_t *);
int _myUnsetEnv(info_t *);
int populate_env_list(info_t *);

/* toem_getenv.c */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* toem_lists1.c */
size_t _list_len(const list_t *);
char **_list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *_node_starts_with(list_t *, char *, char);
ssize_t _get_node_index(list_t *, list_t *);

/* toem_vars.c */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

/* toem_lists.c */
list_t *addNode(list_t **, const char *, int);
list_t *addNodeEnd(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int _delete_node_at_index(list_t **, unsigned int);
void freeList(list_t **);

#endif
