#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - Exchange the values of two integers in an array.
 * @a: The first integer to exchange.
 * @b: The second integer to exchange.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Rearrange a subset of integers using Hoare's scheme.
 * @array: Array of integers.
 * @size: Size of the array.
 * @left: Starting index of the subset to rearrange.
 * @right: Ending index of the subset to rearrange.
 *
 * Return: Final partition index.
 *
 * Description: Employs Hoare's partitioning with the last
 * element as the pivot.
 * Prints the array after every element swap during the process.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int driver, up, down;

	driver = array[right];
	for (up = left - 1, down = right + 1; up < down;)
	{
		do {
			up++;
		} while (array[up] < driver);
		do {
			down--;
		} while (array[down] > driver);

		if (up < down)
		{
			swap_ints(array + up, array + down);
			print_array(array, size);
		}
	}

	return (up);
}

/**
 * hoare_sort - Recursively implements quicksort with the Hoare scheme.
 * @array: Array of integers to sort.
 * @size: Size of the array.
 * @left: Starting index of the partition to order.
 * @right: Ending index of the partition to order.
 *
 * Description: Employs Hoare's partitioning method for efficient sorting.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int belong;

	if (right - left > 0)
	{
		belong = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, belong - 1);
		hoare_sort(array, size, belong, right);
	}
}

/**
 * quick_sort_hoare - Efficiently sort an array of integers
 *                    in ascending order using Hoare's quicksort.
 * @array: Array of integers to be sorted.
 * @size: Size of the array.
 *
 * Description: Implements Hoare's partition scheme and prints
 * the array after each element swap during sorting.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
