#include "sort.h"
#include <stddef.h>

/**
* swap - exchange values in an array
* @x: points to elements in the array
* @y: points to elements in the array
* Effect: Swaps values between @first and @second
* Returns: Always returns 0
*/

void swap(int *x, int *y)
{
int tmp = *x;
*x = *y;
*y = tmp;
}

/**
* bubble_sort - Unleashing the cosmic power to sort
* integers in ascending order.
* @arr: The mystical array to be sorted.
* @size: The cosmic dimension of the array.
*/

void bubble_sort(int *arr, size_t size)
{
size_t i, j;
char isSorted;

for (i = 1; i < size; i++)
{
isSorted = 1;
for (j = 0; j < size - 1; j++)
{
if (arr[j] > arr[j + 1])
{
swap(&arr[j], &arr[j + 1]);
isSorted = 0;
print_array(arr, size);
}
}
if (isSorted == 1)
break;
}
}
