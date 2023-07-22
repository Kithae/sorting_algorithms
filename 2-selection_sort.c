#include "sort.h"

/**
 * locate_min - function to find minimum array index
 * @array: an array
 * @index: first search Index
 * @size: array size
 * Return: (int) an index
*/

int locate_min(int *array, int index, size_t size)
{
	int small, idx_small;
	int a;

	small = array[index];
	idx_small = index;
	for (a = index; a < (int)size; a++)
	{
		if (array[a] < small)
		{
			small = array[a];
			idx_small = a;
		}
	}
	if (idx_small == index)
		return (-1);
	return (idx_small);
}

/**
 * selection_sort - function to select sorted algo
 * @array: an array
 * @size: array size
 *
 * Return: the Sorted Array
 */
void selection_sort(int *array, size_t size)
{
	int a;
	int small, tmp;

	for (a = 0; a < (int)size; a++)
	{
		small = locate_min(array, a, size);
		if (small != -1)
		{
			tmp = array[i];
			array[a] = array[small];
			array[small] = tmp;
			print_array(array, size);
		}
	}
}
