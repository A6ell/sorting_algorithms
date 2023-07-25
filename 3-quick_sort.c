#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm (Lomuto partition scheme).
 *
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    recursive_quick_sort(array, 0, size - 1);
}

/**
 * recursive_quick_sort - Recursive function to perform Quick sort.
 *
 * @array: Pointer to the array to be sorted.
 * @low: Starting index of the partition to be sorted.
 * @high: Ending index of the partition to be sorted.
 */
void recursive_quick_sort(int *array, int low, int high)
{
    int partition_idx;

    if (low < high)
    {
        partition_idx = lomuto_partition(array, low, high);
        recursive_quick_sort(array, low, partition_idx - 1);
        recursive_quick_sort(array, partition_idx + 1, high);
    }
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort.
 *
 * @array: Pointer to the array to be sorted.
 * @low: Starting index of the partition to be sorted.
 * @high: Ending index of the partition to be sorted.
 *
 * Return: The final index of the pivot element.
 */
int lomuto_partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j, tmp;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (i != j)
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
                print_array(array, high + 1);
            }
        }
    }

    if ((i + 1) != high)
    {
        tmp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = tmp;
        print_array(array, high + 1);
    }

    return (i + 1);
}
