#include <stdio.h>
#include "sort.h"

/**
* swap_nodes - Swaps two nodes in a doubly linked list
* @list: Pointer to the head of the list
* @node1: Pointer to the first node to swap
* @node2: Pointer to the second node to swap
*/
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
if (node1->prev)
node1->prev->next = node2;
if (node2->next)
node2->next->prev = node1;

node1->next = node2->next;
node2->prev = node1->prev;
node1->prev = node2;
node2->next = node1;

if (node2->prev == NULL)
*list = node2;

print_list(*list);
}

/**
* insertion_sort_list - Sorts a doubly linked list of integers
*                       in ascending order using the Insertion sort algorithm.
* @list: Pointer to the head of the list
*/
void insertion_sort_list(listint_t **list)
{
listint_t *current;
listint_t *insertion_point;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

current = (*list)->next;

while (current != NULL)
{
insertion_point = current->prev;

while (insertion_point != NULL && current->n < insertion_point->n)
{
swap_nodes(list, insertion_point, current);
insertion_point = current->prev;
}

current = current->next;
}
}
