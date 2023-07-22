#include "sort.h"

/**
 * swap - function for swapping two int
 * @a: 1st int
 * @b: 2nd int
 * Return: the Swaped int
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * partition - function to pivot an array
 * @array: An array
 * @low: an int
 * @high: an int
 * @size: array size
 * Return: pivoted int index
 */
int partition(int *array, int low, int high, size_t size)
{
	int pvt = array[high];
	int a = low - 1, b;

	for (b = low; b <= high; b++)
	{
		if (array[b] <= pvt)
		{
			a++;
			if (a != b)
			{
				swap(&array[a], &array[b]);
				print_array(array, size);
			}
		}
	}
	return (a);
}
/**
 * lomuto_qsort - function that sorts arrays Recursively
 * @array: an array
 * @low: an int
 * @high: an int
 * @size: array size
 * Return: void
 */
void lomuto_qsort(int *array, int low, int high, size_t size)
{
	int a;

	if (low < high)
	{
		a = partition(array, low, high, size);
		lomuto_qsort(array, low, a - 1, size);
		lomuto_qsort(array, a + 1, high, size);
	}
}
/**
 * quick_sort - uses lomuto partition to Sort Algorithms
 * @array: an array
 * @size: array size
 * Return: the Sorted Array
 */
void quick_sort(int *array, size_t size)
{
	lomuto_qsort(array, 0, size - 1, size);
}
