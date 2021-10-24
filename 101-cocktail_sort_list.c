#include "sort.h"

void going_forward(listint_t **left_node, listint_t **right_node)
{
	listint_t *actual = *left_node;

	while (actual->next != NULL)
	{
		actual = actual->next;
		if (actual->next == NULL)
			*right_node = actual;
	}
}
void going_backward(listint_t **left_node, listint_t **start_node)
{
	listint_t *actual = *left_node;

	while (actual->prev != NULL)
	{
		actual = actual->prev;
		if (actual->prev == NULL)
			*start_node = actual;
	}
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 *  in ascending order using the Cocktail shaker sort algorithm
 * @list: list to sort
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *end_node = NULL, *start_node = NULL;

	if (list == NULL || *list == NULL)
		return;

	going_forward(list, &end_node);
	printf("\nThe value of the last node was: [%i]\n", end_node->n);
	going_backward(&end_node, &start_node);
	printf("\nThe value of the first node was: [%i]\n", start_node->n);
}
