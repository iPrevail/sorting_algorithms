#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_sort(int *array, size_t size);

/**
 * swap_ints - Shuffle two integers within an array.
 * @a: Pointer to the first integer for shuffling.
 * @b: Pointer to the second integer for shuffling.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bitonic_merge - Perform a specialized bitonic merge,
 * sorting a designated sequence
 * within an integer array based on given parameters.
 *
 * array:Array of integers.
 * size:Size of the array.
 * start:Start index of the sequence to sort.
 * seq:Size of the sequence to sort.
 * flow:Sorting direction indicator.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
			    (flow == DOWN && array[i] < array[i + jump]))
				swap_ints(array + i, array + i + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - Transform an array into a bitonic
 * sequence block with specified start,
 * size, and sorting direction. Creates a building block for a bitonic
 * sequence.
 *
 * @array: Array of integers.
 * @size: Size of the array.
 * @start: Starting index of the building block.
 * @seq: Size of the building block.
 * @flow: Sorting direction for the bitonic sequence block.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, UP);
		bitonic_seq(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Perform bitonic sort on an integer array, ascending order.
 *
 * @arra: Array to be sorted.
 * @size: Size of the array (must be a power of 2).
 *
 * Description: Implements bitonic sort algorithm and prints
 *              array after each swap. Valid only for size = 2^k.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
