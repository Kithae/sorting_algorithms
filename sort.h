#ifndef _SORTING_H_
#define _SORTING_H_
#include <stdlib.h>
#include <stdio.h>


/** Double Linked List Struct*/

/**
 * struct listint_s - the node for a Doubly linked list
 *
 * @n: a node Integer
 * @prev: Previous element pointer
 * @next: next element pointer
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/** The printing prototypes */

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

/** individual tasks Prototypes */
int len_list(listint_t *h);
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);
void switch_nodes(listint_t **list, listint_t **p);
void selection_sort(int *array, size_t size);
void heapify(int *array, size_t s, size_t root, size_t size);
void quick_recursion(int *array, int left, int right, size_t size);
int partition(int *array, int left, int right, size_t size);
void shell_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void merge_recursion(int *arr, int *array, size_t left, size_t right);
void merge_subarray(int *arr, int *array, size_t left,
		size_t middle, size_t right);
void bitonic_merge(int *array, int l, int r, int direction);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void count_sort_LSD(int *array, size_t size, size_t lsd);
void bitonic_recursion(int *array, int l, int r, int direction, size_t size);
void bubble_sort(int *array, size_t size);

#endif
