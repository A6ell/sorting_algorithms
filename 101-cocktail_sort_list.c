#include "sort.h"

/**
* cocktail_sort_list - Sorts a doubly linked list of integers in ascending order
*                       using the Cocktail shaker sort algorithm.
*
* @list: Pointer to the head of the list
*/
void cocktail_sort_list(listint_t **list)
{
int swapped;
listint_t *current;
listint_t *temp;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

do
{
swapped = 0;
current = *list;

while (current->next != NULL)
{
if (current->n > current->next->n)
{
if (current->prev == NULL)
*list = current->next;
temp = current->next->next;

if (current->next->next != NULL)
current->next->next->prev = current;

current->next->next = current;
current->next->prev = current->prev;

if (current->prev != NULL)
current->prev->next = current->next;

current->prev = current->next;
current->next = temp;

swapped = 1;
print_list(*list);
}
else
current = current->next;
}

if (!swapped)
break;

swapped = 0;
current = current->prev;

while (current->prev != NULL)
{
if (current->n < current->prev->n)
{
if (current->prev->prev == NULL)
*list = current;
temp = current->prev->prev;

if (current->prev->prev != NULL)
current->prev->prev->next = current;

current->prev->prev = current;
current->prev->next = current->next;

if (current->next != NULL)
current->next->prev = current->prev;

current->next = current->prev;
current->prev = temp;

swapped = 1;
print_list(*list);
}
else
current = current->prev;
}
} while (swapped);
}
