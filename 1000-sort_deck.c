#include "deck.h"

/**
 * get_value - Get the integer value of a card.
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The integer value of the card.
 */
int get_value(deck_node_t *card)
{
	if (strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (strcmp(card->card->value, "10") == 0)
		return (10);
	if (strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (strcmp(card->card->value, "Queen") == 0)
		return (12);
        if (strcmp(card->card->value, "King") == 0)
                return (13);
	return (card->card->value[0] - '0');
}

/**
 * insertion_sort_deck_kind - Sort a deck of cards from spades to diamonds.
 * @list: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_kind(deck_node_t **list)
{
	deck_node_t *node = NULL, *tmp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	node = *list;
	node = node->next;
	while (node)
	{
		while (node->prev && node->card->kind < (node->prev)->card->kind)
		{
			tmp = node;
			if (node->next)
				(node->next)->prev = node->prev;
			(node->prev)->next = node->next;
			node = node->prev;
			tmp->prev = node->prev;
			tmp->next = node;
			if (node->prev)
				(node->prev)->next = tmp;
			node->prev = tmp;
			if (tmp->prev == NULL)
				*list = tmp;
			node = node->prev;
		}
		node = node->next;
	}

}

/**
 * insertion_sort_deck_value - Sort a deck of cards according to value.
 * @list: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_value(deck_node_t **list)
{
        deck_node_t *node = NULL, *tmp = NULL;

        if (list == NULL || *list == NULL || (*list)->next == NULL)
                return;

        node = *list;
        node = node->next;
        while (node)
        {
                while (node->prev && node->card->kind == (node->prev)->card->kind
				&& get_value(node) < get_value(node->prev))
                {
                        tmp = node;
                        if (node->next)
                                (node->next)->prev = node->prev;
                        (node->prev)->next = node->next;
                        node = node->prev;
                        tmp->prev = node->prev;
                        tmp->next = node;
                        if (node->prev)
                                (node->prev)->next = tmp;
                        node->prev = tmp;
                        if (tmp->prev == NULL)
                                *list = tmp;
                        node = node->prev;
                }
                node = node->next;
        }

}

/**
 * sort_deck - Sort a deck of cards from ace to king and
 *             from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
