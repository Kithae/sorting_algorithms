#include "sort.h"

/**
 * locate_min - function to locate smallest array index
 * @array: an Array
 * @index: 1st  Index
 * @size: array Size
 * Return: the index
 */

int locate_min(int *array, int index, size_t size)
{
	int tiny, idx_min;
	int a;

	tiny = array[index];
	idx_min = index;
	for (a = index; a < (int)size; a++)
	{
		if (array[a] < tiny)
		{
			tiny = array[a];
			idx_min = a;
		}
	}
	if (idx_min == index)
		return (-1);
	return (idx_min);
}

/**
 * selection_sort - implements the sorted algorithm
 * @array: An array
 * @size: an int
 *
 * Return: the Sorted Array
 */
void selection_sort(int *array, size_t size)
{
	int a;
	int tiny, tmp;

	for (a = 0; a < (int)size; a++)
	{
		tiny = locate_min(array, a, size);
		if (tiny != -1)
		{
			tmp = array[a];
			array[a] = array[tiny];
			array[tiny] = tmp;
			print_array(array, size);
		}
	}
}
