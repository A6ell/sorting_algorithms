#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include "sort.h"
/**
 * struct listint_s - A doubly linked list node structure
 *
 * @n: Integer data stored in the node
 * @prev: Pointer to the previous node in the list
 * @next: Pointer to the next node in the list
 */

typedef struct listint_s
{
int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;


#include <stddef.h>

int lomuto_partition(int *array, int low, int high);
void recursive_quick_sort(int *array, int low, int high);
void quick_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void insertion_sort_list(listint_t **list);
void print_list(const listint_t *list);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
#endif /* SORT_H */
