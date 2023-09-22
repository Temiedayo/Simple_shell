#include "shell.h"
/**
 * _strlen - Returns len of a string
 * @s: String length to be checked
 *
 * Return: Integer len of string
 */
int _strlen(char *s)
{
int i = 0;
if (!s)
return (0);
while (*s++)
i++;
return (i);
}
/**
 * _strcmp - Executes genesis comparison of two strings.
 * @s1: First String
 * @s2: Second String
 *
 * Return: -1 if s1 < s2, 1 if s1 > s2, 0 if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2)
{
if (*s1 != *s2)
return (*s1 - *s2);
s1++;
s2++;
}
if (*s1 == *s2)
return (0);
else
return (*s1 < *s2 ? -1 : 1);
}
/**
 * starts_with - Scans if needle begins with haystack
 * @haystack: String to be searched
 * @needle: Substring to be found
 *
 * Return: Address of next character of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}
/**
 * _strcat - Concatenates 2 strings
 * @dest: Destination buffer
 * @src: Source Buffer
 *
 * Return: Pointer to dest buffer
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
