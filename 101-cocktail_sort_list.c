#include "sort.h"

/**
 * list_len - function for returning list length
 * @list: a list
 *
 * Return: the length
 */
size_t list_len(listint_t *list)
{
	size_t length = 0;

	while (list)
	{
		length++;
		list = list->next;
	}
	return (length);
}

/**
 * switch_nodes - function for swapping nodes at specific
 * @list: a list
 * @p: a node pointer
 */
void switch_nodes(listint_t **list, listint_t **p)
{
	listint_t *a, *b, *c, *d;

	a = (*p)->prev;
	b = *p;
	c = (*p)->next;
	d = (*p)->next->next;
	b->next = d;
	if (d)
		d->prev = b;
	c->next = b;
	c->prev = b->prev;
	if (a)
		a->next = c;
	else
		*list = c;
	b->prev = c;
	*p = c;
}

/**
 *cocktail_sort_list - uses cocktail sort algorithm
* to sort doubly linked list
* @list: a list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *p;
	int curr = 0;

	if (!list || !*list || list_len(*list) < 2)
		return;
	p = *list;
	while (!curr)
	{
		curr = 1;
		while (p->next)
		{
			if (p->n > p->next->n)
			{
				curr = 0;
				switch_nodes(list, &p);
				print_list(*list);
			}
			else
				p = p->next;
		}
		if (curr)
			break;
		p = p->prev;
		while (p->prev)
		{
			if (p->n < p->prev->n)
			{
				curr = 0;
				p = p->prev;
				switch_nodes(list, &p);
				print_list(*list);
			}
			else
				p = p->prev;
		}
	}
}
