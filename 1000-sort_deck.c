#include "deck.h"

/**
 * sort_deck - Sorts a deck of cards.
 * @deck: The deck to be sorted
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *curr;
	size_t len;
	deck_node_t *one, *two, *three, *four;

	len = deck_len(*deck);

	if (!deck || !*deck || len < 2)
		return;

	curr = *deck;
	while (curr)
	{
		if (curr->prev && card_value(curr) < card_value(curr->prev))
		{
			one = curr->prev->prev;
			two = curr->prev;
			three = curr;
			four = curr->next;

			two->next = four;
			if (four)
				four->prev = two;
			three->next = two;
			three->prev = one;
			if (one)
				one->next = three;
			else
				*deck = three;
			two->prev = three;
			curr = *deck;
			continue;
		}
		else
		{
			curr = curr->next;
		}
	}
}

/**
 * card_value - Gets the value of a card.
 * @node: A card in a deck
 * Return: Value between 1 and 52
 */
int card_value(deck_node_t *node)
{
	char *val[13] = {"Ace", "2", "3", "4", "5", "6", "7",
					 "8", "9", "10", "Jack", "Queen", "King"};
	char *kinds[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};
	int i, kind_val = 0;

	for (i = 1; i <= 13; i++)
	{
		if (!_strcmp(node->card->value, val[i - 1]))
		{
			kind_val = i;
		}
	}
	for (i = 1; i <= 4; i++)
	{
		if (!_strcmp(kinds[node->card->kind], kinds[i - 1]))
		{
			kind_val = kind_val + (13 * i);
		}
	}
	return (kind_val);
}

/**
 * _strcmp - Compares two strings.
 * @s1: Pointer to the first string
 * @s2: Pointer to the second string
 * Return: <0 if @s1 is less than @s2, 0 if they're equal,
 * >0 if @s1 is greater than @s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * deck_len - Gets the length of a deck.
 * @list: The deck to get the length of
 * Return: The length of the deck
 */
size_t deck_len(deck_node_t *list)
{
	size_t len = 0;
	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}
