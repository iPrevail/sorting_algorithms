#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/* Specialized macros for bitonic sort comparison direction */
#define UP 0
#define DOWN 1

/**
* struct listint_s - Node of a doubly linked list
* @n: Integer stored in the node
* @next: Pointer to the next element
* @prev: Pointer to the previous element
*
* Description: This structure defines a node for a doubly linked list,
* with an integer value, a pointer to the next element, and a pointer to
* the previous element.
*/

typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *arr, size_t size);
void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/* Sorting algorithms, meticulous conductors of data harmonies. */
void bubble_sort(int *arr, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
#endif
