#include "sort.h"

/**
 * swapper - Swaps a doubly linked list of integers.
 * @holder: Pointer to the array
 * @list: The array to be swapped
 * Return: Pointer to the swapped array
 */
listint_t *swapper(listint_t *holder, listint_t **list)
{
	listint_t *node_holder;

	if (holder->prev->prev != NULL)
		holder->prev->prev->next = holder;

	holder->prev->next = holder->next;
	node_holder = holder->prev->prev;
	holder->prev->prev = holder;

	if (holder->next != NULL)
		holder->next->prev = holder->prev;

	holder->next = holder->prev;
	holder->prev = node_holder;

	if (holder->prev == NULL)
		*list = holder;

	return (holder);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm.
 * @list: The array to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int flag = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list);

	while (flag != 0)
	{
		flag = 0;
		while (current->next != NULL)
		{

			if (current->n > current->next->n)
			{
				current = swapper(current->next, list);
				print_list(*list);
				flag = 1;
			}
			current = current->next;
		}
		current = current->prev;

		while (current->prev != NULL)
		{
			if (current->prev->n > current->n)
			{
				current = swapper(current, list);
				print_list(*list);
				flag = 1;
			}
			else if (current->prev != NULL)
			{
				current = current->prev;
			}
		}
		current = current->next;
	}
}
