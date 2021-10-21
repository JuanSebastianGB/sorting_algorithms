#include "sort.h"

/**
 * make_swap - swap 2 nodes left and right and make the runner from right
 * to left
 * @prev: Prev node
 * @actual: Actual node
 * @head: Head node
 * Return Nothing
 */

void make_swap(listint_t **prev, listint_t *actual, listint_t **head)
{
	(void)actual;
	(void)prev;
	printf("(Prev: %i)", (*prev)->n);
	printf("(Actual: %i)\n", actual->n);
	printf("(Cabecera: %i)\n", (*head)->n);
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *  in ascending order using the Insertion sort algorithm
 * @list: list to look into
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *actual;

	for (actual = (*list)->next; actual != NULL; actual = actual->next)
	{
		if (actual->prev != NULL && actual->n < actual->prev->n)
			make_swap(&actual->prev, actual, list);
	}
}
