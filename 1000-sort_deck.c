#include "deck.h"

/**
 * _strcmp - Compares two strings.
 * @s1: Pointer to the first string
 * @s2: pointer to the second string
 * Return: The integer
 */
int _strcmp(const char *s1, const char *s2)
{
	int i = 0;
	while (*(s1 + i) && *(s2 + i))
	{
		if (s1[i] != s2[i])
			break;
		i++;
	}
	return s1[i] - s2[i];
}

/**
 * get_card_value - Gets integer card value
 * @card: The card
 * Return: The value of the card
 */
int get_card_value(deck_node_t *card)
{
	int value = atoi(card->card->value);
	if (value != 0)
		return (value);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	if (_strcmp(card->card->value, "King") == 0)
		return (13);
	return (0);
}

/**
 * swap_nodes - Swaps nodes in a doubly linked list
 * @prev: Pointer to the previous node
 * @actual: Pointer to the current node
 * @head: Pointer to the head of the deck
 */
void swap_nodes(deck_node_t **prev, deck_node_t *actual, deck_node_t **head)
{
	(*prev)->next = actual->next;

	if (actual->next != NULL)
		actual->next->prev = *prev;

	actual->prev = (*prev)->prev;
	actual->next = *prev;

	if ((*prev)->prev != NULL)
		(*prev)->prev->next = actual;
	else
		*head = actual;

	(*prev)->prev = actual;
	*prev = actual->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: The array to be sorted
 * @option: If 0 sort by value, if 1 sort by kind
 */
void insertion_sort_list(deck_node_t **list, int option)
{
	deck_node_t *actual, *prev;

	if (list == NULL || *list == NULL)
		return;

	for (actual = (*list)->next; actual != NULL; actual = actual->next)
	{
		prev = actual->prev;
		if (!option)
		{
			while (actual->prev != NULL &&
				   get_card_value(actual) < get_card_value(actual->prev))
			{
				swap_nodes(&prev, actual, list);
			}
		}
		else
		{
			while (actual->prev != NULL &&
				   actual->card->kind < actual->prev->card->kind)
			{
				swap_nodes(&prev, actual, list);
			}
		}
	}
}

/**
 * sort_deck - Sorts a deck of cards.
 * @deck: The deck to be sorted
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL)
		return;

	insertion_sort_list(deck, 0);
	insertion_sort_list(deck, 1);
}
