#include "sort.h"
/**
 * swap - function for swapping 2 list elements
 * @head: list head
 * @a: 1st node
 * @b: 2nd node
 */
void swap(listint_t *a, listint_t *b, listint_t **head)
{
	listint_t *asc1 = NULL, *asc2 = NULL;

	if (a == NULL || b == NULL)
		return;
	asc1 = a->prev;
	asc2 = b->next;
	if (asc1)
		asc1->next = b;
	if (asc2)
		asc2->prev = a;
	a->next = asc2;
	a->prev = b;
	b->next = a;
	b->prev = asc1;
	if (asc1 == NULL)
		*head = b;
}
/**
 * insertion_sort_list  - function for inserting sorted list
 * @list: a list
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *prev;
	int num;

	if (list == NULL || (*list)->next == NULL || (*list) == NULL)
	{
		return;
	}
	head = *list;
	while (head)
	{
		prev = head->prev;
				num = head->n;

		while (prev && prev->n > num)
		{
			swap(prev, head, list);
			print_list(*list);
			prev = head->prev;
		}
		head = head->next;
	}
}
