#include "shell.h"
/**
 * _eputs - Prints input string
 * @str: The String
 *
 * Return: Nothing
 */
void _eputs(char *str)
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
 * _eputchar - Writes character c to stderr
 * @c: Character
 *
 * Return: 1 on success, -1 on error
 */
int _eputchar(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(2, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}
/**
 * _putfd - Writes the char c to give fd
 * @c: Character to be printed
 * @fd: File descriptor
 *
 * Return: On success 1.
 * On error, -1 is returned
 */
int _putfd(char c, int fd)
{
static int i;
static char buf[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(fd, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}
/**
 * _putsfd - Output an input string
 * @str: String to print
 * @fd: File descriptor
 *
 * Return: Number of char
 */
int _putsfd(char *str, int fd)
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
