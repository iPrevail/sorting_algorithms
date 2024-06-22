#include "sort.h"

/**
* swap_ints - Rearrange two integers within an array.
* @a: First integer for shuffling.
* @b: Second integer for shuffling.
*/
void swap_ints(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

/**
 * shell_sort - Ascending order sort of an integer array
 *                    employing the Knuth interval sequence.
 * @array: Array of integers to be sorted.
 * @size: Size of the array.
 *
 * Details: Implements the shell sort algorithm with intervals
 *          determined by the Knuth sequence for increased speed.
 */
void shell_sort(int *array, size_t size)
{
size_t gap, m, n;

if (array == NULL || size < 2)
return;

 for (gap = 1; gap < (size / 3);)
gap = gap * 3 + 1;

 for (; gap >= 1; gap /= 3)
{
for (m = gap; m < size; m++)
{
n = m;
while (n >= gap && array[n - gap] > array[n])
{
swap_ints(array + n, array + (n - gap));
n -= gap;
}
}
print_array(array, size);
}
}
