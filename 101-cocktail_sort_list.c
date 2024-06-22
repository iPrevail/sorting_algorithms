#include "sort.h"
#include <stdbool.h>

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
* swap_node_ahead - Adjust the order of a doubly-linked list using
*                      the cocktail shaker algorithm, swapping a node
*                      with its succeeding node.
* @list: Pointer to the list's beginning.
* @tail: Pointer to the list's end.
* @shaker: Pointer to the node undergoing swapping.
*/
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
listint_t *tmp = (*shaker)->next;

if ((*shaker)->prev != NULL)
(*shaker)->prev->next = tmp;
else
*list = tmp;
 tmp->prev = (*shaker)->prev;
(*shaker)->next = tmp->next;
if (tmp->next != NULL)
tmp->next->prev = *shaker;
else
*tail = *shaker;
 (*shaker)->prev = tmp;
tmp->next = *shaker;
*shaker = tmp;
}

/**
* swap_node_behind - Rearranges a node in a doubly-linked list of integers,
*                   swapping it with the preceding node.
* @list: Pointer to the list's head.
* @tail: Pointer to the list's tail.
* @shaker: Pointer to the node being rearranged (Cocktail Shaker Algorithm).
*/
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
listint_t *tmp = (*shaker)->prev;

if ((*shaker)->next != NULL)
(*shaker)->next->prev = tmp;
else
*tail = tmp;
 tmp->next = (*shaker)->next;
(*shaker)->prev = tmp->prev;
if (tmp->prev != NULL)
tmp->prev->next = *shaker;
else
*list = *shaker;
 (*shaker)->next = tmp;
tmp->prevshaker = *shaker;
*shaker = tmp;
}

/**
* cocktail_sort_list - Orchestrates the graceful dance of integers in a
*                      doubly-linked list, arranging them in ascending order
*                      through the elegant cocktail shaker algorithm.
* @list: A maestro's wand, conducting a listint_t symphony with finesse.
*/
void cocktail_sort_list(listint_t **list)
{
listint_t *tail, *shaker;
bool shaken_not_stirred = false;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

 for (tail = *list; tail->next != NULL;)
tail = tail->next;

 while (shaken_not_stirred == false)
{
shaken_not_stirred = true;
for (shaker = *list; shaker != tail; shaker = shaker->next)
{
if (shaker->n > shaker->next->n)
{
swap_node_ahead(list, &tail, &shaker);
print_list((const listint_t *)*list);
shaken_not_stirred = false;
}
}
for (shaker = shaker->prev; shaker != *list;
shaker = shaker->prev)
{
if (shaker->n < shaker->prev->n)
{
swap_node_behind(list, &tail, &shaker);
print_list((const listint_t *)*list);
shaken_not_stirred = false;
}
}
}
}
