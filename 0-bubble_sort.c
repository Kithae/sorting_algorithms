#include "sort.h"

/**
 *bubble_sort - a function for sorting int arrays in ascending order
 *@array: an array
 *@size: array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t b, a;
	int c;

	if (size < 2)
		return;
	for (a = 0; a < size - 1; a++)
	{
		for (b = 0; b < size - a - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				c = array[b];
				array[b] = array[b + 1];
				array[b + 1] = c;
				print_array(array, size);
			}
		}
	}
}
