#include "shell.h"
/**
 * interactive - Returns True if shell is an interactive mode
 * @info: The struct address
 *
 * Return: 1 interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * is_delim - Scans if character is a delimeter
 * @c: Character to be checked
 * @delim: Delimeter string
 * Return: 1 True, 0 False
 */
int is_delim(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
return (1);
return (0);
}
/**
 * _isalpha - Scans for an Alphabetic character
 * @c: character
 * Return: 1 if c is an alphabet, 0 if otherwise
 */
int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}
/**
 * _atoi - Changes string to an integer
 * @s: String changed
 * Return: 0 if no num in string
 */
int _atoi(char *s)
{
int i, sign = 1, flag = 0, output;
unsigned int result = 0;
for (i = 0; s[i] != '\0' && flag != 2; i++)
{
if (s[i] == '-')
sign *= -1;
if (s[i] >= '0' && s[i] <= '9')
{
flag = 1;
result *= 10;
result += (s[i] - '0');
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
