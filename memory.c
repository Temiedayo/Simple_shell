#include "shell.h"
/**
 * bfree - Frees pointer and NULLs address
 * @ptr: Address of pointer to be freed
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}
