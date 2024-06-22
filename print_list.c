#include <stdio.h>
#include "sort.h"

/**
 * print_list - Outputs a sequence of integers
 *
 * @list: The integer sequence to be displayed
 */
void print_list(const listint_t *list)
{
	int i;

	i = 0;
	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		++i;
		list = list->next;
	}
	printf("\n");
}
