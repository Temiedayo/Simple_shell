#include "shell.h"
/**
 * list_len - Finds the length of linked list
 * @h: Pointer to the first node
 *
 * Return: Magnitude of the list
 */
size_t list_len(const list_t *h)
{
size_t i = 0;
while (h)
{
h = h->next;
i++;
}
return (i);
}
/**
 * list_to_strings - Returns the array of strings of the list->str
 * @head: Pointer to the first node
 *
 * Return: An Array of the strings
 */
char **list_to_strings(list_t *head)
{
list_t *node = head;
size_t i = list_len(head), j;
char **strs;
char *str;
if (!head || !i)
return (NULL);
strs = malloc(sizeof(char *) * (i + 1));
if (!strs)
return (NULL);
for (i = 0; node; node = node->next, i++)
{
str = malloc(_strlen(node->str) + 1);
if (!str)
{
for (j = 0; j < i; j++)
free(strs[j]);
free(strs);
return (NULL);
}
str = _strcpy(str, node->str);
strs[i] = str;
}
strs[i] = NULL;
return (strs);
}
/**
 * print_list - Outputs all the elements of a list_t linked list
 * @h: Pointer to the first node
 *
 * Return: Magnitude of list
 */
size_t print_list(const list_t *h)
{
size_t i = 0;
while (h)
{
_puts(convert_number(h->num, 10, 0));
_putchar(':');
_putchar(' ');
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
i++;
}
return (i);
}
/**
 * node_starts_with - Returns node whose string begins qwith prefix
 * @node: Pointer to the list head
 * @prefix: String to match
 * @c: Next char after prefix to match
 *
 * Return: Matching node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
char *p = NULL;
while (node)
{
p = starts_with(node->str, prefix);
if (p && ((c == -1) || (*p == c)))
return (node);
node = node->next;
}
return (NULL);
}
/**
 * get_node_index - Acquires the index of node
 * @head: Pointer to the list head
 * @node: Pointer to node
 *
 * Return: Index of node, or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
size_t i = 0;
while (head)
{
if (head == node)
return (i);
head = head->next;
i++;
}
return (-1);
}
