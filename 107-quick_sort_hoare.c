#include "sort.h"

/**
 * swap - function that swaps two integers
 * @a: int
 * @b: int
 * Return: (void) Swaped int
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * partition - uses pivot to partition an array
 * @array: the array
 * @low: int
 * @high: int
 * @size: array size
 * Return: pivot address
 */
int partition(int *array, int low, int high, size_t size)
{
	int pvt = array[high];
	int x = low, y = high;

	while (1)
	{
		while (array[x] < pvt)
			x++;
		while (array[y] > pvt)
			y--;

		if (x < y)
		{
			swap(&array[x], &array[y]);
			print_array(array, size);
			x++;
			y--;
		}
		else
		{
			if (x != y)
				return (y);
			return (y - 1);
		}
	}
}
/**
 * hoare_qsort - Sorts  an Array recursively
 * @array: the array
 * @low: min array value
 * @high: max array value
 * @size: the array size
 * Return: void
 */
void hoare_qsort(int *array, int low, int high, size_t size)
{
	int x;

	if (low < high)
	{
		x = partition(array, low, high, size);
		if (x > low)
			hoare_qsort(array, low, x, size);
		hoare_qsort(array, x + 1, high, size);
	}
}
/**
 * quick_sort_hoare - uses hoare partition to sort Algorithm
 * @array: the array
 * @size: array size
 * Return: an Array, sorted
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	hoare_qsort(array, 0, size - 1, size);
}
