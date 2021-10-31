#include "deck.h"

/**
 * get_card_value - Getting the int card value to work with
 * @card: Actual card to get value
 * Return: Card's Value
 *
 */

int get_card_value(deck_node_t *card)
{
	int value = atoi(card->card->value);

	if (value != 0)
		return (value);
	if (strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (strcmp(card->card->value, "Queen") == 0)
		return (12);
	if (strcmp(card->card->value, "King") == 0)
		return (13);
	return (0);
}

/**
 * swap_nodes - Swap nodes in a double linked list
 * @prev: pointer to prev node
 * @actual: pointer o actual node
 * @head: to the head of the deck
 * Return: Nothing
 */

void swap_nodes(deck_node_t **prev, deck_node_t *actual,
				deck_node_t **head)
{
	(*prev)->next = actual->next;
	if (actual->next != NULL)
		actual->next->prev = *prev;
	actual->prev = (*prev)->prev;
	actual->next = *prev;
	if ((*prev)->prev != NULL)
		(*prev)->prev->next = actual;
	else
		*head = actual; /* prev node is NULL*/
	(*prev)->prev = actual;
	*prev = actual->prev;
}

/**
 * implement_going_back - Implements going back for sorting algorythm
 * to left
 * @prev: Prev node
 * @actual: Actual node
 * @head: Head node to print list
 * @option: sort by value if 0, otherwise sort by kind
 * Return Nothing
 */

void implement_going_back(deck_node_t **prev, deck_node_t *actual,
						  deck_node_t **head, int option)
{
	if (!option)
		while (actual->prev != NULL && get_card_value(actual) < get_card_value(actual->prev))
			swap_nodes(prev, actual, head);
	else
		while (actual->prev != NULL && actual->card->kind < actual->prev->card->kind)
			swap_nodes(prev, actual, head);
}

/**
 * insertion_sort_list - sorts a deck of cards
 *  in ascending order using the Insertion sort algorithm
 * @list: list to look into
 * @option: sort by value if 0, otherwise sort by kind
 * Return: Nothing
 */

void insertion_sort_list(deck_node_t **list, int option)
{
	deck_node_t *actual, *prev;

	if (list == NULL || *list == NULL)
		return;
	for (actual = (*list)->next; actual != NULL; actual = actual->next)
	{
		prev = actual->prev;
		implement_going_back(&prev, actual, list, option);
	}
}

/**
 * sort_deck - sorts a deck of cards.
 * @deck: Deck to sort
 * Return: Nothing
 *
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL)
		return;
	insertion_sort_list(deck, 0);
	insertion_sort_list(deck, 1);
}
