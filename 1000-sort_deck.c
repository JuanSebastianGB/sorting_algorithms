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
 * sort_deck - sorts a deck of cards.
 * @deck: Deck to sort
 * Return: Nothing
 *
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL)
		return;
	while (*deck)
	{
		printf("El valor de la carta actual es: %d\n", get_card_value(*deck));
		*deck = (*deck)->next;
	}
}
