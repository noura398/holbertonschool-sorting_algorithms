#include "sort.h"

/**
 * swap_adjacent - swaps two adjacent nodes (left, right) in a doubly list
 * @list: address of head pointer
 * @left: left node (must be right->prev)
 * @right: right node (must be left->next)
 *
 * Description: Rewires pointers and updates head when needed.
 */
static void swap_adjacent(listint_t **list, listint_t *left, listint_t *right)
{
	listint_t *Lprev, *Rnext;

	Lprev = left->prev;
	Rnext = right->next;

	/* connect left's previous to right */
	if (Lprev)
		Lprev->next = right;
	right->prev = Lprev;

	/* connect right to left */
	right->next = left;
	left->prev = right;

	/* connect left to right's next */
	left->next = Rnext;
	if (Rnext)
		Rnext->prev = left;

	/* update head if needed */
	if (right->prev == NULL)
		*list = right;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm
 * @list: address of the head pointer to the list
 *
 * Description:
 * - You are not allowed to modify the n value of a node; swap nodes instead.
 * - Print the list after each swap using print_list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *scan;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	while (curr)
	{
		scan = curr;
		/* Bubble the current node backward into correct position */
		while (scan->prev && scan->prev->n > scan->n)
		{
			swap_adjacent(list, scan->prev, scan);
			print_list(*list);
		}
		curr = curr->next;
	}
}

