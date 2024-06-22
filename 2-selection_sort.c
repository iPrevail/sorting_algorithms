#include "sort.h"

/**
 * swap_ints - Swap values of two integers within an array.
 * @a: The first integer to interchange.
 * @b: The second integer to interchange.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Arrange integers in ascending order
 *               via selection sort.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Functionality: Displays array post each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t j, k;

	if (array == NULL || size < 2)
		return;

	for (j = 0; j < size - 1; j++)
	{
		min = array + j;
		for (k = j + 1; k < size; k++)
			min = (array[k] < *min) ? (array + k) : min;

		if ((array + j) != min)
		{
			swap_ints(array + j, min);
			print_array(array, size);
		}
	}
}
