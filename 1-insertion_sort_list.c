#include "sort.h"

/**
 * insertion_sort_list - A function that
 * sorts a doubly linked list of integers
 * in ascending order using the Insertion
 * sort algorithm.
 * @list: A pointer to the list we need
 * to sort.
 * Return: nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *my_list = NULL;
	listint_t *swap_list = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}
	my_list = *list;

	while (my_list != NULL)
	{
		swap_list = my_list;
		while (swap_list->prev != NULL && swap_list->prev->n > swap_list->n)
		{
			if (swap_list->next == NULL)
			{
				swap_list->prev->next = NULL;
			}
			else
			{
				swap_list->next->prev = swap_list->prev;
				swap_list->prev->next = swap_list->next;
			}
			swap_list->next = swap_list->prev;
			swap_list->prev = swap_list->prev->prev;
			swap_list->next->prev = swap_list;
			if (swap_list->prev == NULL)
			{
				*list = swap_list;
			}
			else
			{
				swap_list->prev->next = swap_list;
			}
			print_list(*list);
		}
		my_list = my_list->next;
	}
}
