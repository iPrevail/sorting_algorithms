#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid, size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Meticulously sorts a designated integer subarray.
 * @subarr: The targeted subarray of integers awaiting precision.
 * @buff: A specialized buffer housing the artfully sorted subarray.
 * @front: The inception point, marking the front index of the array journey.
 * @mid: The nexus, encapsulating the middle index with harmonious precision.
 * @back: The conclusion, reaching the back
 * index to complete the orchestrated sort.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid, size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Orchestrates a recursive
 * merge sort in descending order.
 * @subarr: Subarray of integers awaiting sorting prowess.
 * @buff: A sanctuary for the unfolding sorted symphony.
 * @front: The inception of the subarray's journey.
 * @back: The grand finale of the subarray's performance.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - Rearrange integers in ascending order
 *               using the innovative ascend_sort algorithm.
 * @array: Array of integers to be sorted.
 * @size: Number of elements in the array.
 *
 * Description: Employs a unique top-down sorting approach
 *              to efficiently organize the given integers.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
